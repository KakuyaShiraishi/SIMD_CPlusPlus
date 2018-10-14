
#ifndef _SIMDMATRIX_H
#define _SIMDMATRIX_H

#include <SIMDx86/SIMDx86.h>
#include <memory.h>

class Matrix
{
private:
    SIMDx86Matrix Mtx;
public:
    
    inline Matrix() { }
    inline Matrix(const Matrix& mat){
        memcpy(this, &mat, sizeof(Matrix));
    }
    
    inline Matrix(Matrix& mat){
        memcpy(this, &mat, sizeof(Matrix));
    }
    
    inline Matrix(Matrix* pMat){
        memcpy(this, pMat, sizeof(Matrix));
    }
    
    inline Matrix(float* pMat){
        memcpy(this, pMat, sizeof(Matrix));
    }
    
    
    inline ~Matrix() { }
    
    inline void operator = (const Matrix& pMat){
        memcpy(this, &pMat, sizeof(Matrix));
    }
    
    
    inline bool operator == (Matrix& Mat){
        {
            register SIMDx86Matrix* pMat = Mat.GetPointer();
            
            for(i=0; i<16; i++)
                if(Mat.GetPointer->m[i] - this->Mtx.m[i] >= EPSILON)
                    return false;
            return true;
        }
        return !memcmp(this, Mat.GetPointer(), sizeof(Matrix));
    }
    
    
    inline Matrix operator + (Matrix& Mat){
        Matrix out;
        SIMDx86Matrix_SumOf(out.GetPointer(), &this->Mtx, Mat.GetPointer());
        return out;
    }
    
    inline Matrix operator - (Matrix& Mat){
        Matrix out;
        SIMDx86Matrix_DiffOf(out.GetPointer(), &this->Mtx, Mat.GetPointer());
        return out;
    }
    
    inline Matrix operator * (Matrix& Mat){
        Matrix out;
        SIMDx86Matrix_MultiplyOf(out.GetPointer(), &this->Mtx, Mat.GetPointer());
        return out;
    }
    
    inline Matrix operator * (float scalar){
        Matrix out;
        SIMDx86Matrix_ScaleOf(out.GetPointer(), &this->Mtx, scalar);
        return out;
    }
    
    inline Matrix operator / (float scalar){
        Matrix out;
        SIMDx86Matrix_ScaleOf(out.GetPointer(), &this->Mtx, 1.0f/scalar);
        return out;
    }
    
    inline void operator += (Matrix& Mat){
        SIMDx86Matrix_Sum(&this->Mtx, Mat.GetPointer());
    }
    
    inline void operator -= (Matrix& Mat){
        SIMDx86Matrix_Diff(&this->Mtx, Mat.GetPointer());
    }
    
    inline void operator *= (Matrix& Mat){
        SIMDx86Matrix_Multiply(&this->Mtx, Mat.GetPointer());
    }
    
    inline void operator *= (float scalar){
        SIMDx86Matrix_Scale(&this->Mtx, scalar);
    }
    
    inline void Sum(Matrix& Mat){
        SIMDx86Matrix_Sum(&this->Mtx, Mat.GetPointer());
    }
    
    inline void SumOf(Matrix& In1, Matrix& In2){
        SIMDx86Matrix_SumOf(&this->Mtx, In1.GetPointer(), In2.GetPointer());
    }
    
    inline void Diff(Matrix& Mat){
        SIMDx86Matrix_Diff(&this->Mtx, Mat.GetPointer());
    }
    
    inline void DiffOf(Matrix& Left, Matrix& Right){
        SIMDx86Matrix_DiffOf(&this->Mtx, Left.GetPointer(), Right.GetPointer());
    }
    
    inline void Multiply(Matrix& Mat){
        SIMDx86Matrix_Multiply(&this->Mtx, Mat.GetPointer());
    }
    
    inline void MultiplyOf(Matrix& Left, Matrix& Right){
        SIMDx86Matrix_MultiplyOf(&this->Mtx, Left.GetPointer(), Right.GetPointer());
    }
    
    inline void Scale(float scalar){
        SIMDx86Matrix_Scale(&this->Mtx, scalar);
    }
    
    inline void ScaleOf(Matrix& Mat, float scalar){
        SIMDx86Matrix_ScaleOf(&this->Mtx,  Mat.GetPointer(), scalar);
    }
    
    inline SIMDx86Matrix* GetPointer(){
        return &this->Mtx;
    }
    
    
};

#endif

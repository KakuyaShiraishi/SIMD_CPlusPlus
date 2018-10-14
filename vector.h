
#ifndef _SIMDVECTOR_H
#define _SIMDVECTOR_H

#include <SIMDx86/SIMDx86.h>

class Vector
{
private:
    SIMDx86Vector Vec;
public:
    
    inline Vector(){
    }
    
    inline Vector(float x, float y, float z){
        this->Vec.x = x;
        this->Vec.y = y;
        this->Vec.z = z;
    }
    
    inline Vector(Vector& v){
        this->Vec.x = v.GetPointer()->x;
        this->Vec.y = v.GetPointer()->y;
        this->Vec.z = v.GetPointer()->z;
    }
    
    inline ~Vector(){
    }
    
    inline Vector operator + (Vector& v){
        Vector out;
        
        SIMDx86Vector_SumOf(out.GetPointer(), this->GetPointer(), v.GetPointer());
        return out;
    }
    
    inline void operator + (){
        this->Vec.x = +this->Vec.x;
        this->Vec.y = +this->Vec.y;
        this->Vec.z = +this->Vec.z;
    }
    
    inline Vector operator - (Vector& v){
        Vector out;
        
        SIMDx86Vector_DiffOf(out.GetPointer(), this->GetPointer(), v.GetPointer());
        return out;
    }
    
    inline void operator - (){
        this->Vec.x = -this->Vec.x;
        this->Vec.y = -this->Vec.y;
        this->Vec.z = -this->Vec.z;
    }
    
    inline float operator * (Vector& v){
        return SIMDx86Vector_Dot(this->GetPointer(), v.GetPointer());
    }
    
    inline Vector operator ^ (Vector& Vec){
        Vector out;
        
        SIMDx86Vector_CrossOf(out.GetPointer(), this->GetPointer(), Vec.GetPointer());
    }
    
    inline void operator ~ (){
        SIMDx86Vector_Normalize(this->GetPointer());
    }
    
    inline bool operator == (Vector& v){
        return (this->Vec.x == v.GetPointer()->x) && (this->Vec.y == v.GetPointer()->y) && (this->Vec.z == v.GetPointer()->z);
    }
    
    inline void operator = (Vector& v){
        this->Vec.x = v.GetPointer()->x;
        this->Vec.y = v.GetPointer()->y;
        this->Vec.z = v.GetPointer()->z;
    }
    
    inline SIMDx86Vector* GetPointer(){
        return &this->Vec;
    }
    
    
};

#endif

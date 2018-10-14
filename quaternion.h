
#ifndef _SIMDQUATERNION_H
#define _SIMDQUATERNION_H

#include <SIMDx86/SIMDx86.h>

class Quaternion
{
private:
    SIMDx86Quaternion q;
public:
    inline Quaternion(){
    }
    
    inline Quaternion(Quaternion& Quat){
        this->q.x = Quat.GetPointer()->x;
        this->q.y = Quat.GetPointer()->y;
        this->q.z = Quat.GetPointer()->z;
        this->q.w = Quat.GetPointer()->w;
    }
    
    inline Quaternion(float x, float y, float z, float w){
        this->q.x = x;
        this->q.y = y;
        this->q.z = z;
        this->q.w = w;
    }
    
    inline ~Quaternion(){
    }
    
    inline Quaternion operator * (Quaternion& Quat){
        Quaternion out;
        SIMDx86Quaternion_MultiplyOf(out.GetPointer(), this->GetPointer(), Quat.GetPointer());
        return out;
    }
    
    inline Quaternion operator *= (Quaternion& Quat){
        SIMDx86Quaternion_Multiply(this->GetPointer(), Quat.GetPointer());
    }
    
    inline Quaternion Slerp(Quaternion& Quat, float scalar){
        Quaternion out;
        SIMDx86Quaternion_Slerp(out.GetPointer(), this->GetPointer(), Quat.GetPointer(), scalar);
        return out;
    }
    
    inline void Rotate(float rads, float x, float y, float z){
        SIMDx86Quaternion_Rotate(this->GetPointer(), rads, x, y, z);
    }
    
    inline void operator ~ (){
        SIMDx86Quaternion_Normalize(this->GetPointer());
    }
    
    inline SIMDx86Quaternion* GetPointer(){
        return &this->q;
    }
    
};

#endif

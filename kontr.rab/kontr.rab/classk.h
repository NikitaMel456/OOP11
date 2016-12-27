#pragma once
class Koord
{
public:
	
		
		int x;
		int y;
		int z;
		
		Koord() : x(0), y(0), z(0) {};
		Koord(int xx, int yy, int zz) { x = xx; y = yy; z = zz; };
	    ~Koord();
	
	friend Koord  operator +(Koord &A, Koord &B)
	{
		
		return Koord( A.x + B.x, A.y + B.y, A.z + B.z);
	};
	friend Koord  operator -(Koord &A, Koord &B)
	{
		
		return Koord( A.x - B.x, A.y - B.y, A.z - B.z);
	};
	
	friend int operator ==(Koord &X, Koord &Y)
	{
		return ((X.x == Y.x) && (X.y == Y.y) && (X.z == Y.z));
	}
	friend int operator !=(Koord &X, Koord &Y)
	{
		return ((X.x != Y.x) || (X.y != Y.y) || (X.z != Y.z));
	}
};
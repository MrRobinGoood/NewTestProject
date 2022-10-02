#include <iostream>

double findRootsQuadraticEquation(int ratioA, int ratioB, int ratioC) {
	
	//при а!=0 b=0 c=0 возвращаемое значение 0 является удвоенным единственным корнем уравнения.
	if ((ratioA == 0) || (ratioB == 0 && ratioC == 0)) { return 0; }

	if (ratioB == 0)
	{
		if (-ratioC / ratioA > 0)
		{
			return (sqrt(-ratioC / ratioA));
		}
		else { return 0; }
	}

	if (ratioC == 0) 
	{
		//если второй корень отрицательный, то возвращаемое значение 0 является корнем уравнения.
		if (-ratioB/ratioA>0) 
		{
			return (-ratioB / ratioA);
		}
		else { return 0; }
	}
	
	double discriminant = pow(ratioB, 2) - 4 * ratioA * ratioC;
	
	if (discriminant < 0) {	return 0;}
	
	if (discriminant == 0)
	{
		return ((-ratioB + sqrt(discriminant)) / (2 * ratioA)) * 2;
	}
	
	if (discriminant > 0)
	{
		double rootX = (-ratioB + sqrt(discriminant)) / (2 * ratioA);
		double rootY = (-ratioB - sqrt(discriminant)) / (2 * ratioA);
		if (rootX > rootY) { return rootX; }
		else { return rootY; }
	}	
}

int main()
{	
	std::cout << findRootsQuadraticEquation(5, 2, -4);
}

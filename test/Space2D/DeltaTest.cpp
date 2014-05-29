#include "Space2DTest.h"

int main(void)
{
	cout<<"Wheel spinning at 1 radian per iteration:"<<endl<<"Position"<<endl;
	Delta<Radians> rotationalVelocity;
	for(rotationalVelocity = Radians(1.0); rotationalVelocity.get() < 10.0; rotationalVelocity.increment())
		cout<<double(rotationalVelocity.get())<<endl;
	
	cout<<"Now lets start trying to spin it the other way. Every 5 iterations we'll decrease the speed by one third of a radian per iteration"<<endl<<"Position\tVelocity"<<endl;
	for(int i = 0; i < 4; i++)
	{
		rotationalVelocity -= Radians(2.0/3.0);
		for(int j = 0; j < 5; j++)
		{
			cout<<double(rotationalVelocity.get())<<'\t'<<double(rotationalVelocity)<<endl;
			rotationalVelocity.increment();
		}
	}
	
	cout<<"Das p cool, but I want continuity. Let's increase the Delta every instant, using a delta"<<endl<<"Position\tVelocity\tAcceleration"<<endl;
	for(Delta<Delta<Radians> > rotationalAccel(Delta<Radians>(Radians(0.2)), rotationalVelocity); rotationalAccel.get() < 100.0; rotationalAccel.increment())
		cout<<double(rotationalAccel.get(Delta<Radians>::N_DERIVATIVE))<<'\t'<<
		double(rotationalAccel.get(Delta<Delta<Radians> >::N_DERIVATIVE))<<'\t'<<
		double(rotationalAccel)<<endl;
	
	cout<<"Wowee. I wonder what else this thing can do..."<<endl;
	return 0;
}
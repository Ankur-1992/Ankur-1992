#include <iostream>
#include <vector>
using namespace std;
class Subject;
class Observer
{
	public:
		Subject *sub;
		virtual void update() =0;
		
};
class Subject
{
	public:
		vector <Observer *> observers;
		public:
			void Attach(Observer *obj)
			{
				observers.push_back(obj);
			}
			void Detach(Observer *obj)
			{
				
			}
			void Notify()
			{
				for (int i=0;i< observers.size();i++)
					observers[i]->update();
			}
			virtual void SetState(string value) = 0;
			virtual string GetState()= 0;
};
class ConcreteSubject :public Subject
{
	private:
		//int state;
		string whatsaapgrp;

	public:
		void SetState(string value)
		{
			whatsaapgrp = value;
			Notify();
		}
		string GetState()
		{
			return whatsaapgrp;
		}
};

class ConcreteObserverA: public Observer
{
	private:
		//int state;
		string whatsaapgrp;
		public:
			ConcreteObserverA(Subject *obj)
			{
				sub = obj;
				sub->Attach(this);
			}
			void update()
			{
				cout<<"Inside ConcreteObserverA::update() \n"<<endl;
				whatsaapgrp = sub->GetState();
				cout<<"whatsaapgrp ="<<whatsaapgrp<<endl;
			}			
};
class ConcreteObserverB: public Observer
{
	private:
		//int state;
		string whatsaapgrp;
		public:
			ConcreteObserverB(Subject *obj)
			{
				sub = obj;
				sub->Attach(this);
			}
			void update()
			{
				cout<<"Inside ConcreteObserverB::update() \n"<<endl;
				whatsaapgrp = sub->GetState();
				cout<<"whatsaapgrp ="<<whatsaapgrp<<endl;
			}			
};


int main()
{
	Subject *sub1 = new ConcreteSubject();
	Subject *sub2 = new ConcreteSubject();
	
	Observer *objs1 = new ConcreteObserverA(sub1);
	Observer *objs2 = new ConcreteObserverB(sub2);
	
	sub1->SetState("FamilyGroup");
	sub2->SetState("OfficeGroup");
	return 0;
}
	



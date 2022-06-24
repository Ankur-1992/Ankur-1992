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
			virtual void SetState(int value) = 0;
			virtual int GetState()= 0;
};
class ConcreteSubject :public Subject
{
	private:
		int state;

	public:
		void SetState(int value)
		{
			state = value;
			Notify();
		}
		int GetState()
		{
			return state;
		}
};

class ConcreteObserverA: public Observer
{
	private:
		int state;
		public:
			ConcreteObserverA(Subject *obj)
			{
				sub = obj;
				sub->Attach(this);
			}
			void update()
			{
				cout<<"Inside ConcreteObserverA::update() \n"<<endl;
				state = sub->GetState();
				cout<<"State ="<<state<<endl;
			}			
};
class ConcreteObserverB: public Observer
{
	private:
		int state;
		public:
			ConcreteObserverB(Subject *obj)
			{
				sub = obj;
				sub->Attach(this);
			}
			void update()
			{
				cout<<"Inside ConcreteObserverB::update() \n"<<endl;
				state = sub->GetState();
				cout<<"State ="<<state<<endl;
			}			
};

int main()
{
	Subject *obj = new ConcreteSubject();
	
	Observer *obj1 = new ConcreteObserverA(obj);
	Observer *obj2 = new ConcreteObserverB(obj);
	
	obj->SetState(10);
	obj->SetState(20);
	return 0;
}
	



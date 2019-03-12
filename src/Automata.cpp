#include "Automata.h"
ostream& operator <<(ostream& out,const STATES&t){
	switch(t){
		case OFF:return(out<<"OFF");
		case WAIT:return(out<<"WAIT");
		case ACCEPT:return(out<<"ACCEPT");
		case CHECK:return(out<<"CHECK");
		case COOK:return(out<<"COOK");
	}
	return(out);
}
Automata::Automata(){
	state=OFF;
}
STATES Automata::on(){
	if(state==OFF){
		state=WAIT;
		cash=0;
		select=-1;
	}
	return state;
}
STATES Automata::off(){
	if((state==WAIT)&&(cash==0)) state=OFF;
	if((state==WAIT)&&(cash!=0)){
		giveChange();
		state=OFF;
	}
	return state;
}
STATES Automata::coin(int money){
	if(state==WAIT){
		cash=money;
		state=ACCEPT;
	}
	else throw "State is not wait!";
	return state;
}
void Automata::printMenu(){
	if (state==OFF) on();
	cout<<"Menu:\n";
	for(int i=0;i<N;i++)
		cout<<i<<' '<<menu[i]<<"  "<<prices[i]<<"rubles"<<endl;
}
void Automata::printState(){
	cout<<state<<endl;
}
STATES Automata::choise(int f){
	if((state==ACCEPT)&&(f>=0)&&(f<=N)){
		printMenu();
		select=f;
		state=CHECK;
	}
	return state;
	
}
bool Automata::check(){
	if((select!=-1)&&(cash>=prices[select])&&(state==CHECK))
		return true;
	cancel();
	return false; 
}
STATES Automata::cancel(){
	if(state!=COOK)
		state=WAIT;
	return state;
}
STATES Automata::cook(){
	if(check()==true)
	    state=COOK;
	return state;
}
STATES Automata::finish(){
	if(state==COOK){ 
		state=WAIT;
		cash=cash-prices[select];
		select=-1;
	}
	return state;
}
int Automata::giveChange(){
	int change=0;
	if (state==WAIT){
		change=cash;
		cout<<"Change is "<<change<<" rubles\n";
		cash=0;
	}
	return change;
}

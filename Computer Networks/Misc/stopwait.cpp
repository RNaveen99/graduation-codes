#include<iostream>
#include<cstdio>
#include<cstring>
//#include<conio.h>
#include<cstdlib>
#include "protocol.h"
using namespace std;

class stop_and_wait
 { char buf[50];
	event_type event;
	public:
	 stop_and_wait()
	  { for(int i=0;i<50;i++)
		  { buf[i]=0;}
	  }
	 void sender();
	 void receiver();
 };

int k=0,ccount=0,len=0,lim=10000;

void stop_and_wait::sender()
 {   cout<<"\n\n\t\t\t**********Sender Side**********\n";

	 if(ccount>0)
		  { cout<<"\n\tFeedback frame received : ";
			 cout<<"\n\tKind = ";
			 showkind(r->kind);
			 cout<<" Ack = "<<r->ack;
		  }

	 if(ccount==lim)
	  { cout<<"\n\tData Sent Successfully";
		 cout<<"\n\tData :";
		 cout << buf;
		 exit(0);
	  }

	 if(k==0)
	  { cout<<"Enter data to be sent :";
		 cin.getline(buf,49);
			 len=strlen(buf);
			  if(len%5==0)
				{ lim=len/5;}
			  else
				{ lim=len/5+1;}
		 cout<<"\n\n\tDividing data into groups(5-bit each).....";
			k++;
	  }

  while(ccount<lim)
	{  while(event!=wait)
		 {
			cout<<"\n\tPutting data D"<<ccount+1<<" in a packet....";
			p=new packet;
			  for(int i=0;i<5;i++)
				{ p->data[i]=buf[i+ccount*5]; }
			cout<<"\n\n\tPassing data to datalink layer......";
			event=frame_arrival;
			  if(wait_for_event(event))
				{   from_network_layer(p);
					 to_physical_layer(s);
					 event=wait;
				}
			  ccount++;
			  receiver();
		 }
	}

 }

void stop_and_wait::receiver()
 {   cout<<"\n\n\t\t\t**********Receiver Side**********";
	if(event==wait)
	  { from_physical_layer(s);
		 to_network_layer(p);
		 to_physical_layer(r);
		 event=frame_arrival;
		 sender();
	  }
 }


int main()
{ stop_and_wait ob;
	ob.sender();
	
	return 0;
}


#include<iostream>

using namespace std;

//language for which recursive descent parser is implimented 
//E->i=iE'
//E'->+iE'|*iE'|/iE'|%iE'|-iE'|epsilon
//input belongs to (i,+,-,*,/,%,=)
//this is for parsing any basic expressions 

void err(string input,int s,int f)
{
	cout<<"\nERROR\n";
	for(int i=s;i<=f && input[i]!='$';i++)
    {
    cout<<input[i]<<" ";
    }
    cout<<":the input does not match any productions ";
}
void E1(string input,int lookahead)
{
	if(input[lookahead]=='-' || input[lookahead]=='+' || input[lookahead]=='*' || input[lookahead]=='/' || input[lookahead]=='%')
	{
	  if(input[lookahead+1]=='i')
	   { cout<<"E ";

          for(int i=3;input[i]!='$';i++)
           {
             if(i<=lookahead)
             {
              cout<<"E' ";
              i++;
             }
             else
             cout<<input[i]<<" ";
           }
	      cout<<endl;
	      E1(input,lookahead+2);
	    }     
	   else
	   {
	     err(input,lookahead,lookahead+1);
	     return;
	   }
	}
	else if(input[lookahead]=='$')
	{
	 cout<<"parsing successfull\n ";
	}
	else
	{
	  err(input,lookahead,lookahead+1);
	}
}

void E(string input,int lookahead)
{
	if(input[lookahead]=='i' && input[lookahead+1]=='=' && input[lookahead+2]=='i')
	{
	  cout<<"E ";
	  for(int i=3;input[i]!='$';i++)
	  cout<<input[i];

	  cout<<endl;
	  lookahead=3;
      E1(input,lookahead);
    }
   else
   {
     err(input,0,2);
     return;
   }
}



int main()
{
	string input="";
	int lookahead=0;
	cout<<"enter the string to be parsed "<<endl;
	cin>>input;
	input=input+'$';
    if(input[0]=='$')
    {cout<<"empty string";}
    E(input,lookahead);
    
	return 1;
}


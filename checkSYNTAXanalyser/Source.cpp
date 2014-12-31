#include <iostream>
#include <string>
#include <fstream>


using namespace std;

string input[1000];
int lookUp(string temp);
string temp="";
int index=0;
int lexIndex=0;
int errorIndex=0; 
int syni=0;
int sf=0;
struct error
{
string err;
string msg;
};
error e1[1000];

struct lex
{
	string token;
	string lexeme;
};
lex l1[1000];

void inserterror(string e,string m)
{
e1[errorIndex].err=e;
e1[errorIndex].msg=m;
errorIndex++;
}
void Displayerr()
{
if(errorIndex==0)
{
cout<<"\n 0 ERRORS\n";
}
	for(int i=0;i<errorIndex;i++)
	{
	cout<<e1[i].err<<"  ,  "<<e1[i].msg<<endl;
	
	}
}

void insert(string t, string l)
{

l1[lexIndex].token=t;
l1[lexIndex].lexeme=l;
lexIndex++;
	
}

int lookUp(string temp)
{
	int i=0 , flag=0;
	while(i<lexIndex)
	{
		if(l1[i].lexeme==temp)
		{
	        flag=1;
			break;
		}
		else
		{
		i++;
		}

	}
	return flag;
}



void Display()
{
	for(int i=0;i<lexIndex;i++)
	{
cout<<l1[i].lexeme<<"  ,  "<<l1[i].token<<endl;;

	}
}

/////////////////////IDENTIFIER SYNTAX///////////////////////
void iden()
{
	int d=0;
 sf=0;
 
	if(l1[syni].lexeme=="Cchar" || l1[syni].lexeme=="Cint")
	{
		
		syni++;
	}
 
else{
	cout<<syni;
   	cout<<"ERROR#1!NO VARIABLE DECLARATIONS";
	sf=1;
cout<<"Not found";;
	}
if(l1[syni].token=="Identifier")
	{
		syni++;
	}
	  else
	{
		cout<<"ERROR#1!INVALID DECLARATION";
		sf=1;
	cout<<"Not found";;
	  }
	 if(l1[syni].lexeme==":" ||l1[syni].lexeme=="==")
	 {
		 if(l1[syni].lexeme=="==")
		 {
			 d=1;
		 }
	 syni++;
	 }
	 else if(d!=1 && l1[syni].lexeme!=":") 	{
		cout<<"ERROR#1!ERROR after variable  declaration missing : before "<<l1[syni+1].lexeme;
		sf=1;
cout<<"Not found";;	
	}
if(d==1)
{
 if( (l1[syni].token=="Integer Constant" && l1[syni-1].lexeme=="=="   && l1[syni-3].lexeme=="Cint") || (l1[syni-1].lexeme=="==" && l1[syni].token=="Char Constant" && l1[syni-3].lexeme=="Cchar") )
{
	 cout<<syni;
			syni++;cout<<syni;
}
 else  if( (l1[syni].token=="Integer Constant" && l1[syni-1].lexeme=="=="   && l1[syni-3].lexeme!="Cint") || (l1[syni-1].lexeme=="==" && l1[syni].token=="Char Constant" && l1[syni-3].lexeme!="Cchar") )
{
			cout<<"ERROR#1!INVALID DECLARATION";
		sf=1;
	cout<<"Not found";;

}


 
 cout<<l1[syni].lexeme;
if( l1[syni].lexeme==":")
	{
		syni++;	
	}
else 
	{
		cout<<"//missing : before "<<l1[syni+1].token;
		sf=1;
cout<<"Not found";;
	}
}
}

////////////////////EXPRESSION syntax////////////////////
void expression()
{
  if(l1[syni].token=="Identifier" ||l1[syni].token=="Integer Constant")
	 {
	 syni++;
	 }
  else
	{
   	cout<<"ERROR#2!Illegal expression after"<<l1[syni-1].lexeme;
	sf=3;
cout<<"Not found";;
	}

  if(l1[syni].lexeme=="++" || l1[syni].lexeme=="--"|| l1[syni].lexeme=="%%"|| l1[syni].lexeme=="//"|| l1[syni].lexeme=="**")
	
	 {
	 syni++;
	 }
  else 
{
   	cout<<"ERROR#2!NO Operator found after"<<l1[syni-1].lexeme;
	sf=3;
cout<<"Not found";;
	}

  if(l1[syni].token=="Identifier" ||l1[syni].token=="Integer Constant")
	 {
	 syni++;
	 }
  else
 {
   	cout<<"ERROR#2!Illegal expression after"<<l1[syni-1].lexeme;
	sf=3;
cout<<"Not found";;
	}
 
  if(l1[syni].lexeme=="==")
	 {
	 syni++;
	 }
 else
	{
   	cout<<"ERROR#2!Illegal expression after"<<l1[syni-1].lexeme;
	sf=3;
cout<<"Not found";;
	}
 
  if(l1[syni].token=="Identifier")
	 {
	 syni++;
	 }
  else	{
   	cout<<"ERROR!Illegal expression after"<<l1[syni-1].lexeme;
	sf=3;
cout<<"Not found";;
	}

 if(l1[syni].lexeme==":")
	{
		syni++;
	}
else	{
		cout<<"ERROE#2 error in expression missing : before "<<l1[syni+1].lexeme;
		sf=1;
cout<<"Not found";;	
	}

}
void loop()
{

}
void condition()
{

  if(l1[syni].token=="Identifier" || l1[syni].token=="Integer Constant")
	 {
	 syni++;
	 }
  else
	{
   	cout<<"ERROR#5!Illegal condition statement after !";
	sf=2;
cout<<"Not found";;
	}
  if(l1[syni].lexeme==">>" || l1[syni].lexeme=="<<" || l1[syni].lexeme=="=")
	{
   	syni++;
}
  else	{
   	cout<<"ERROR#5!Illegal condition after"<<l1[syni-1].lexeme;
	sf=2;
cout<<"Not found";;
}
 
 if(l1[syni].token=="Identifier" || l1[syni].token=="Integer Constant")
	{
   syni++;
}
 
 else 
	{
   	cout<<"ERROR!Illegal condition after"<<l1[syni-1].lexeme;
	sf=2;
cout<<"Not found";;
 }
}
//////////////////////Loop if Else///////////////
void statements()
	 {
	 if(l1[syni].token=="Keyword")
	 {
	 syni++;
	 }
	 else
	 {
	 sf=4;
	 cout<<"ERROR#4 illegal conditional statement after"<<l1[syni-1].lexeme;
	 cout<<"Not found";;
	 }
	 if(l1[syni].lexeme=="!")
	 {
	 syni++;
	 }
	 else
	 {
	 sf=4;
	 cout<<"ERROR#4 illegal conditional statement after"<<l1[syni-1].lexeme;
	 cout<<"Not found";;
	 }
	 while(l1[syni].lexeme!="!!")
	 {
	   if(sf==2)
	 {
		 cout<<"Not found";;
	 }
	 condition();
	 }
	 if(l1[syni].lexeme=="!!")
	 {
		 syni++;
	 }
	 else
	 {
	 sf=4;
	 cout<<"ERROR#4 illegal conditional statement after"<<l1[syni-1].lexeme;
	 cout<<"Not found";;
	}
	  if(l1[syni].lexeme=="[")
	 {
		 syni++;
	 }
	 else
	 {
	 sf=4;
	 cout<<"ERROR#4 illegal conditional statement after"<<l1[syni-1].lexeme;
	 cout<<"Not found";;
	}
	 while(l1[syni].token=="Identifier" || l1[syni].token=="Integer Constant")
   {
    if(sf==3)
	{
	cout<<"Not found";;
	}
	expression();
 }
	  if(l1[syni].lexeme=="]")
	 {
		 syni++;
	 }
	 else
	 {
	 sf=4;
	 cout<<"ERROR#4 illegal conditional statement after"<<l1[syni-1].lexeme;
	 cout<<"Not found";;
	}
}
///////////////////SYNTAX ANALAZYER///////////////////////////////////////
void syntax_analyzer()
{

	if(syni!=lexIndex-1)
	{	
	if((l1[syni].lexeme)=="{" && (l1[syni+1].lexeme)=="}")
	{
	
		cout<<"0 ERRORS";
	cout<<"Not found";;
	}
	if(l1[syni].lexeme!="{")
	{
		cout<<"ERROR! PROGRAM START SYMBOL NOT FOUND";
      cout<<"Not found";;
	}
   else if(l1[syni].lexeme=="{")
	{
	syni++;
	cout<<"Not found";;
	}
   	if(l1[lexIndex-1].lexeme!="}")
	{
	cout<<"ERROR! END bracket Missing";
	cout<<"Not found";;
	}
  
 while(l1[syni].lexeme=="Cchar" || l1[syni].lexeme=="Cint" )
   {
    
	if(sf==1){
	cout<<"Not found";;
	}
	iden();
 }
 while(l1[syni].token=="Identifier" || l1[syni].token=="Integer Constant")
   {
    if(sf==3)
	{
	cout<<"Not found";;
	}
	expression();
 }
 while(l1[syni].token=="Keyword")
 {
	 statements();
 }
	 if(l1[syni].lexeme=="}")
	 {
		 cout<<"0 errors";
		 cout<<"Not found";;
	 }


}
}
int main()
{
string space="";
	for(int o=0;o<1000;o++)
	{
		input[o]="";

	}
	temp="";
//////////////FILING////////////////////////////////
ifstream infile;
infile.open("myfil.txt");
if(!infile.good())
{
cout<<"ERROR READING FILE";
cout<<"Not found";;
}
while(!infile.eof())
{
infile>>temp;
input[index]=temp;
index++;

infile.ignore();
}
infile.close();
///////////////////////checks/////////////////////////
for(int i=0;i<index;i++)
{
	int rslt=0;
	char strng[20]="";
    int f1=0 , m=0 , f2=0 , m2=0;
	int len=input[i].length();

	for(int k=0;k<len;k++)
	{
		strng[k]=input[i].at(k);
		
	}
//////////////////KeyWords///////////////////////////////
	if(input[i]=="iff")
	{
			
	//	rslt=lookUp(input[i]);

		if(rslt==0)
		{
			insert("Keyword",input[i]);
		}

	}
	else if(input[i]=="els")
	{
		//rslt=lookUp(input[i]);
	
		if(rslt==0)
		{
			insert("Keyword",input[i]);
		}
	}
	else if(input[i]=="till")
	{
		//rslt=lookUp(input[i]);
	if(rslt==0)
	{
	insert("Keyword",input[i]);
	}
	}
	else if(input[i]=="untill")
	{
	//rslt=lookUp(input[i]);
	if(rslt==0)
	{
		insert("Keyword",input[i]);
	
	}
	}
	else if(input[i]==":")
	{
	//	rslt=lookUp(input[i]);
	if(rslt==0)
	{
	insert("Ending Symbol",input[i]);
	}}
	else if(input[i]=="[")
	{
	//	rslt=lookUp(input[i]);
	if(rslt==0)
	{
	insert("Opening Square Bracket",input[i]);
	}}
	else if(input[i]=="]")
	{
	//	rslt=lookUp(input[i]);
	if(rslt==0)
	{
	insert("Closing Square Bracket",input[i]);
	}}
	else if(input[i]=="!")
	{
	//	rslt=lookUp(input[i]);
	if(rslt==0)
	{
	insert("Condition Symbol",input[i]);
	}}
	else if(input[i]=="!!")
	{
	//	rslt=lookUp(input[i]);
	if(rslt==0)
	{
	insert("Condition Symbol",input[i]);
	}}
	else if(input[i]=="Cchar")
	{
	//	rslt=lookUp(input[i]);
	if(rslt==0)
	{
	insert("Data Type Character",input[i]);
	}}
	else if(input[i]=="Cint")
	{
	//	rslt=lookUp(input[i]);
	if(rslt==0)
	{
	insert("Data Type Integer",input[i]);
	}}
	else if(input[i]=="{")
	{
	//	rslt=lookUp(input[i]);
	if(rslt==0)
	{
	insert("Program Start Symbol",input[i]);
	}}
	else if(input[i]=="}")
	{
	//	rslt=lookUp(input[i]);
	if(rslt==0)
	{
	insert("Program Ending Symbol",input[i]);
	}}
	else if(input[i] =="show")
					{
	//	rslt=lookUp(input[i]);
	if(rslt==0)
	{
					insert("Keyword",input[i]);
					}
	}
		
	//////////////// Operators//////////
	else if(input[i]=="++")
	{
	//	rslt=lookUp(input[i]);
	if(rslt==0)
	{
	insert("Addition Operator",input[i]);
	}}
	else if(input[i]=="--")
	{
	//	rslt=lookUp(input[i]);
	if(rslt==0)
	{
	insert("Subtraction Operator",input[i]);
	}}
	else if(input[i]=="**")
	{
	//	rslt=lookUp(input[i]);
	if(rslt==0)
	{
	insert("Multiplication Operator",input[i]);
	}}
		else if(input[i]=="//")
	{
	//		rslt=lookUp(input[i]);
	if(rslt==0)
	{
	insert("Division Operator",input[i]);
		}}
			else if(input[i]=="%%")
	{
	//			rslt=lookUp(input[i]);
	if(rslt==0)
	{
	insert("Modulus Operator",input[i]);
			}}
				else if(input[i]=="==")
	{
	//				rslt=lookUp(input[i]);
	if(rslt==0)
	{
	insert("Assingment Operator",input[i]);
				}}
				else if(input[i]=="=")
	{
	//				rslt=lookUp(input[i]);
	if(rslt==0)
	{
	insert("Comparison Operator",input[i]);
				}}
					else if(input[i]==">>")
	{
	//					rslt=lookUp(input[i]);
	if(rslt==0)
	{
	insert("Logical Operator",input[i]);
					}}
						else if(input[i]=="<<")
	{
	//						rslt=lookUp(input[i]);
	if(rslt==0)
	{
	insert("Logical Operator",input[i]);
						}}
////////////////Comments/////////////
						else if(input[i]=="*@")
	{
	//						rslt=lookUp(input[i]);
	if(rslt==0)
	{
	insert("Comment Symbol",input[i]);
						}}
//////////////////Identifiers//////////////////
					
	else if(strng[0]=='$')
					{
	//	rslt=lookUp(input[i]);
	if(rslt==0)
	{
					insert("Identifier",input[i]);
	}				}
	
	else if(input[i]=="")
	{
		space="Space";
	
	}
	
/////////////////////Numeric Constant/////////////////////////////
		else if((static_cast<int> (strng[0])>=48) && (static_cast<int> (strng[0])<=57))
		{
			while(m<len)
			{
				if((static_cast<int> (strng[m])>=48) && (static_cast<int> (strng[m])<=57))
				{
					f1++;m++;
				}

			}
	
			if(f1==len)
			{
			insert("Integer Constant",input[i]);
			}
			else
			{
		    inserterror("ILLEGAL INPUT SYMBOL",input[i]);

			}
		}
	
		
//////////////////////////////////////////////////Character Constant////////////////
	else if(((static_cast<int> (strng[0])>=65) && (static_cast<int> (strng[0])<=90)) || ((static_cast<int> (strng[0])>=97) && (static_cast<int> (strng[0])<=122)) )
	{
	while(m2<len)
	{
	if(((static_cast<int> (strng[m2])>=65) && (static_cast<int> (strng[m2])<=90)) || ((static_cast<int> (strng[m2])>=97) && (static_cast<int> (strng[m2])<=122)))	
		{
		f2++;m2++;
		}

	}

    if(f2==len)
	{
	insert("Char Constant",input[i]);
	}
	else
	{
	 inserterror("ILLEGAL INPUT SYMBOL",input[i]);

	}
	}
		
	///////////////////////ILLEGAL COMMENT ERROR////////////
		else if(strng[0]=='*' && strng[1]!='@')
	{
	inserterror("Ilegal Comment Symbol",input[i]);
	}
	
	////////////////////////ILLEGAL INPUT SYMBOL Errors////////////////////
	
	else 
	{
		inserterror("ILLEGAL INPUT SYMBOL",input[i]);
	}
	
}
cout<<"\n\t\tLEXEME AND TOKEN PAIR\n";
        Display();
cout<<"\n\t\tERRORS\n";
 Displayerr();
 syntax_analyzer();
 system("pause");
  return 0;
}


#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<math.h>
#include<algorithm>
#include<set>
using namespace std;
//node struct
typedef struct MyStruct
{
	string name;
	int thisnum;
	int next1;
	int next2;
}InputStruct;
#pragma region variable
fstream ifile;
fstream ofile;
string toreadpla;//read pla(string) a line
char  *output,*outputname,*inputname;//matrix of input output name
string *formulaLogic;//logic formula
char **formulalogicout;//logic formula of out
bool IsP, Ise;//is p or e the last word of line
int howmanyp = 0, howmanyin = 0, howmanyo = 0, temofp = 0, thisoutputnamenum = 0;//howmany num for me  temofp is to count i need to run howmany times of p
InputStruct *input;//my node
#pragma endregion
void ProcessingString();//to process pla
void initialoftjsPro();//initial of my
void todoPerfectBinaryTree();//make tree
void recreciveForTree(int,int,int,int,int);//initial tree
void recurciveofTruthtable(int, const int,int,int,bool,bool,int);//to give my tree truth-table
void reducebianrytree(int);//make perfecttree
bool  isforpowoftwo(int );//judge is pow of 2
void ouputmydotfile();//output
int main(int argc, char *argv[])
{
	//讀檔
	//ifile.open(argv[1], ios::in );//輸入檔cmd
	//ofile.open(argv[2], ios::out);//輸出檔cmd
	ifile.open("input-2.pla", ios::in );//input test
	ofile.open("output.dot", ios::out);//output test

		initialoftjsPro();
	
		while (getline(ifile, toreadpla))//read a line once again
		{
			if (IsP)
			{
				ProcessingString();//process my file
				temofp -= 1;
				if (temofp <= 0) IsP = false;
			}
			else
				ProcessingString();//process my file
			if (Ise) break;//the end of the file
		}
		todoPerfectBinaryTree();
		reducebianrytree(pow(2,howmanyin)-1);
		ouputmydotfile();
		/////
/*#pragma region test
		//test
		for (int i = 0; i < howmanyin; i++)
		{
			cout << inputname[i] << " ";
		}
		for (int i = 0; i < howmanyo; i++)
		{
			cout << outputname[i] << " ";
		}
		cout << endl;


		for (int i = 0; i < howmanyp; i++)
		{
			cout << "logic:  " << formulaLogic[i] << endl;
		}
		for (int i = 0; i < howmanyp; i++)
		{
			for (int j = 0; j < howmanyo; j++)
			{
				int truethpit = 0;
				cout << formulalogicout[i][j];
			}
			cout << endl;
		}
		cout << endl;
		//

		int forfor = pow(2, howmanyin);
		cout << forfor << endl;
		for (int i = 0; i < forfor; i++)
		{
			cout << input[i].thisnum << "   :   " << input[i].name << " = " << input[i].next1 << endl;
			cout << input[i].thisnum << "   :   " << input[i].name << " = " << input[i].next2 << endl;
		}
		//  
#pragma endregion*/

		
		////////
		ifile.close();
		ofile.close();
	system("pause");
	return 0;
}
//pla process
void ProcessingString() {


	if (!IsP)
	{
		for (int i = 0; i<toreadpla.length(); i++)
		{
			
			//kill space
			if (toreadpla[i]!=' '||toreadpla[i]!='　'){
				//the head is .
				if (toreadpla[i] == '.'){
					//////
					#pragma region i
					
					if (toreadpla[i + 1] == 'i' && (toreadpla[i + 2] == ' ' || toreadpla[i + 2] == '　')){
						string temforpla;
						int howmanyinput = 0;//howmany input
						temforpla.clear();//clear
						stringstream tem;
						tem.str("");//clear
						tem.clear();
						for (int j = i + 2; j < toreadpla.length(); j++)//howmany number
						{
							if (toreadpla[j] != ' '&& toreadpla[j] != '　') {
								for (int k = j; k < toreadpla.length(); k++)
								{
									if (toreadpla[k] != ' ' && toreadpla[k] != '　')
										temforpla += toreadpla[k];
									else break;
								}
								break;
							}
						}
						tem << temforpla;
						tem >> howmanyinput;//howmany input
						howmanyin = howmanyinput;//copyone to remind (global)
						
						inputname = new char[howmanyinput];//how many name
						int t = pow(2, howmanyinput) + 1;
						input = new InputStruct[t];
						break;
					}
#pragma endregion
					//////
					#pragma region o
					else if (toreadpla[i + 1] == 'o' && (toreadpla[i + 2] == ' ' || toreadpla[i + 2] == '　')) {//o
						string temforpla;
						int howmanyouput = 0;//howmany input
						temforpla.clear();//clear
						stringstream tem;
						tem.str("");//clear
						tem.clear();
						for (int j = i + 2; j < toreadpla.length(); j++)//howmany number
						{
							if (toreadpla[j] != ' ' && toreadpla[j] != '　') {
								for (int k = j; k < toreadpla.length(); k++)
								{
									if (toreadpla[k] != ' ' && toreadpla[k] != '　')
										temforpla += toreadpla[k];
									else break;
								}
								break;
							}
						}
						tem << temforpla;
						tem >> howmanyouput;
						howmanyo = howmanyouput;//(global) howmany output
						output = new char[(int)pow(2, howmanyouput)];//to pow 2
						outputname = new char[howmanyouput];//out's name
						break;
						
					}
#pragma endregion
					//////
					#pragma region e
					else if(toreadpla[i + 1] == 'e' && (toreadpla[i + 2] == ' ' || toreadpla[i + 2] == '　')){
						Ise = true;//this program is over
						break;
					}
#pragma endregion
					//////
					#pragma region p
					else if (toreadpla[i + 1] == 'p' && (toreadpla[i + 2] == ' ' || toreadpla[i + 2] == '　')) {
						string temforpla;
						temforpla.clear();//clear
						stringstream tem;
						tem.str("");//clear
						tem.clear();
						for (int j = i + 2; j < toreadpla.length(); j++)//howmany number
						{
							if (toreadpla[j] != ' '&&toreadpla[j] != '　') {
								for (int k = j; k < toreadpla.length(); k++)
								{
									if (toreadpla[k] != ' '&& toreadpla[k] != '　')
										temforpla += toreadpla[k];
									else break;
								}
								break;
							}
						}
						tem << temforpla;
						tem >> howmanyp;//howmany p
						temofp = howmanyp;
						formulaLogic = new string[howmanyp];//howmany formula of logic
						formulalogicout = new char*[howmanyp];//howmany output
						for (int a = 0; a <howmanyp; a++)
						{
							formulalogicout[a] = new char[howmanyo];
						}
						IsP = true;//the next input is p
						break;
					}
#pragma endregion
					//////
					#pragma region ilb
					else if (toreadpla[i + 1] == 'i' && toreadpla[i + 2] == 'l'&& toreadpla[i + 3] == 'b' &&(toreadpla[i + 4] == ' ' || toreadpla[i + 4] == '　')) {
						int tocountin = 0;
						for (int j = i + 5; j < toreadpla.length(); j++)//howmany number
						{
							
							if (toreadpla[j] != ' ' && toreadpla[j] != '　') {
								if (tocountin >= howmanyin) break;
								else {
									inputname[tocountin] =toreadpla[j];//give name to inputnmae matrix
									tocountin += 1;
								}
							}
						}
						break;
					}
					
#pragma endregion
					//////
					#pragma region ob
					else if (toreadpla[i + 1] == 'o' && toreadpla[i + 2] == 'b'&& (toreadpla[i + 3] == ' ' || toreadpla[i + 3] == '　')) {
						int tocountout = 0;
						for (int j = i + 4; j < toreadpla.length(); j++)//howmany number
						{
							
							if (toreadpla[j] != ' ' && toreadpla[j] != '　') {
								if (tocountout >=howmanyo) break;
								else {
									outputname[tocountout] = toreadpla[j];//give output name to outputname matrix
									tocountout += 1;
								}
							}
						}
						break;
					}
#pragma endregion
					/////
				}
				//to process "//"
				else if (toreadpla[i] == '/'&&toreadpla[i + 1] == '/') break;
			}
			
		}
	}
	else
	{
		int whichoneoflogic = 0;
		bool IsIN = false;

		for (int i = 0; i <toreadpla.length(); i++)
		{
			if (toreadpla[i] != ' '&& toreadpla[i] != '　') {
				//input
				int thistemofp = howmanyp - temofp;
				if (!IsIN)
				{
					
					formulaLogic[thistemofp] += toreadpla[i];
					whichoneoflogic++;
					if (whichoneoflogic >= howmanyin) {
						whichoneoflogic = 0;
						IsIN = true;
					}
				}
				else
				{
					
					
					if (toreadpla[i] == '1') {
						formulalogicout[thistemofp][whichoneoflogic]=toreadpla[i];
						whichoneoflogic++;
					}
					else if (toreadpla[i] == '0') {
						formulalogicout[thistemofp][whichoneoflogic] = toreadpla[i];
						whichoneoflogic++;
					}

					if (whichoneoflogic >= howmanyo) {
						whichoneoflogic = 0;
						break;
					}
				}
			}
			
		}

	}

	
}
//initial
void initialoftjsPro() {
	toreadpla.clear();
	delete [] input;
	delete [] output;
	delete [] inputname;
	delete [] outputname;
	delete [] formulaLogic;
	for (int i = 0; i < howmanyp; i++)
	{
		delete[] formulalogicout[i];
	}
	delete[] formulalogicout;
	IsP = false;
	Ise = false;
	howmanyin = 0;
	howmanyo = 0;
	howmanyp = 0;
	temofp = 0;
}
//make tree
void todoPerfectBinaryTree() {
	input[0].name = "0";
	input[0].thisnum = 0;
	input[0].next1 = 0;
	input[0].next2 = 0;
	int tem = pow(2, howmanyin);
	
	input[tem].name = "1";
	input[tem].thisnum =tem;
	input[tem].next1 = 0;
	input[tem].next2 = 0;
	recreciveForTree(howmanyin,1,1,0,1);
	
}
// initial tree (every tree's son are 0&0)
void recreciveForTree(int n,int inital,int count,int nametem,int toc){//
	if (toc>=n){
		//truth-table give  0 0
		for (int i = count; i < pow(2, inital); i++)
		{
			input[i].name = inputname[nametem];
			input[i].thisnum = i;
			input[i].next1 = 0;
			input[i].next2 = 0;
		}
		//judge output
		if (howmanyo > 1)
		{
			cout << "which output?" << endl;
			for (int i = 0; i < howmanyo; i++)
			{
				cout << outputname[i] << "  ";
			}
			cout << endl << "make choice please! to input what you wnat " << endl;
			char inputofoutputnametochioce;
			int outputnamenum = 0;
			cin >> inputofoutputnametochioce;

			for (int i = 0; i < howmanyo; i++)
			{
				if (inputofoutputnametochioce == tolower(outputname[i]) || inputofoutputnametochioce == toupper(outputname[i]))
				{
					outputnamenum = i;
					thisoutputnamenum = i;
					break;
				}
			}
			for (int i = 0; i < howmanyp; i++)
			{

				int truethpit = 0;
				//cout << "真質表" << formulalogicout[i][j] << endl;
				if (formulalogicout[i][outputnamenum] == '1')
				{
					truethpit = pow(2, howmanyin);
				}
				recurciveofTruthtable(1, truethpit, 0, 1, false, false, i);

			}
		}
		else
			thisoutputnamenum = 0;
		{
			for (int i = 0; i < howmanyp; i++)
			{
				
					int truethpit = 0;
					//cout << "真質表" << formulalogicout[i][j] << endl;
					if (formulalogicout[i][0] == '1')
					{
						truethpit = pow(2, howmanyin);
					}
					recurciveofTruthtable(1, truethpit, 0, 1, false, false, i);
				
			}
		}
		

	}
	else {
		
		for (int i =count; i < pow(2,inital); i++)
		{
			input[i].name = inputname[nametem];
			input[i].next1 = i * 2;
			input[i].next2 = i * 2 + 1;
			input[i].thisnum = i;
		}			
		recreciveForTree(n,inital+1,pow(2,inital),nametem+1,toc+1);
		return;
	}
	
}
//to use truthtable for our son
void recurciveofTruthtable(int next,const int truenum,int nextnum,int me,bool right,bool left,int i){
	//cout << next << "  " << truenum << "  " << nextnum << "  " << me << " " << right << "  " << left << endl;
	if (nextnum == howmanyin) {
		if (right) input[me].next2 = truenum;
		if (left) input[me].next1 = truenum;

		//cout <<input[me].thisnum<<":=" <<input[me].name << "=" << input[me].next1 << "   " << input[me].next2 << endl;
		
		}
	else {
		if (formulaLogic[i][nextnum] == '1') {
			me = input[next].thisnum;
			//cout <<next<<"              "<< input[me].thisnum << ":=" << input[me].name << "=" << input[me].next1 << "   " << input[me].next2 << endl;
			recurciveofTruthtable(input[next].next2, truenum, nextnum + 1,me,true,false,i);


		}
		else if (formulaLogic[i][nextnum] == '-') {
			me = input[next].thisnum;
			//cout << next << "              " << input[me].thisnum << ":=" << input[me].name << "=" << input[me].next1 << "   " << input[me].next2 << endl;
			recurciveofTruthtable(input[next].next1, truenum, nextnum + 1,me,false,true,i);
			//cout << next << "              " << input[me].thisnum << ":=" << input[me].name << "=" << input[me].next1 << "   " << input[me].next2 << endl;
			recurciveofTruthtable(input[next].next2, truenum, nextnum + 1,me,true, false,i);

		}
		else if (formulaLogic[i][nextnum] == '0') {
			me = input[next].thisnum;
			//cout << next << "              " << input[me].thisnum << ":=" << input[me].name << "=" << input[me].next1 << "   " << input[me].next2 << endl;
			recurciveofTruthtable(input[next].next1, truenum, nextnum + 1,me,false,true,i);
		}
	}
	
}
//judge pow 2
bool  isforpowoftwo(int n) {
	int i = 0;
	bool r;
	while (1)
	{
		if (n == pow(2, i))
		{
			r = true;
			break;
		}
		else if(n<pow(2,i))
		{
			r = false;
			break;
		}
		i++;
		
	}

	
	return r;
}
//reduce the tree
void reducebianrytree(int initial) {
	if (initial == 1)
	{
		return;
	}
	//the childern are same?
	else if (input[initial].next1 == input[initial].next2)
	{	//is the first one that level
		int temi = initial - 1;
		int temoftreenum[999], count = 0;
		temoftreenum[count] = initial;
		if (!isforpowoftwo(initial)){
			bool first = false;
			//the first of that level not run
			while (1)
			{
				if (input[temi].next1 == input[initial].next1&&input[temi].next2 == input[initial].next2)
				{
					first = true;
					++count;
					temoftreenum[count] = temi;
					--temi;
					if (isforpowoftwo(temi+1)) break;
				}
				else break;
			}
			if (first)
			{
				for (int i = 0; i <= count; i++)
				{
					if (temoftreenum[i] % 2 == 0)
					{
						int a = temoftreenum[i] / 2;
						input[a].next1 = input[initial].next1;

					}
					else {
						int a = (temoftreenum[i] - 1) / 2;
						input[a ].next2 = input[initial].next2;
					}
				}
			}
			else
			{
				if (initial % 2 == 0)
				{
					int a = initial / 2;
					input[a].next1 = input[initial].next1;

				}
				else {
				int a = (initial - 1) / 2;
					
					input[a].next2 = input[initial].next2;
					
				}
			}
		}
		else {
			if (temoftreenum[initial] % 2 == 0)
			{
				int a = initial / 2;
				input[a].next1 = input[initial].next1;
				
			}
			else {
				int a = (initial-1)/ 2;
				input[a].next2 = input[initial].next2;
			}
		}
		reducebianrytree(temoftreenum[count]-1);

	}
	else
	{
		int temi = initial - 1;
		int temoftreenum[999], count = 0;
		temoftreenum[count] = initial;
		if (!isforpowoftwo(initial)) {
			temoftreenum[count] = initial;
			//the first of that level not run
			while (1)
			{
				if (input[temi].next1 == input[initial].next1&&input[temi].next2 == input[initial].next2)
				{
					++count;
					temoftreenum[count] = temi;
					--temi;
					if (isforpowoftwo(temi + 1)) break;
				}
				else break;
			}
			for (int i = 1; i <=count; i++)
			{
				if (temoftreenum[i] % 2 == 0)
				{
					int a = temoftreenum[i] / 2;
					input[a].next1 = initial;
				}
				else {
					int a = (temoftreenum[i]-1)/ 2;
					input[a].next2 = initial;
				}
			}
		}
		reducebianrytree(temoftreenum[count]-1);
	}

}
//output
void ouputmydotfile() {
	int last = pow(2, howmanyin);
	set<int>myset;
	myset.insert(1);
	

	int forfor = pow(2, howmanyin);
	//cout << forfor << endl;
	for (int i = 1; i < forfor; i++)
	{
		if (input[i].next1 != 0 && input[i].next1 != forfor)
		{
			myset.insert(input[i].next1);
		}
	 if (input[i].next2 != 0 && input[i].next2 != forfor)
		{
			myset.insert(input[i].next2);
		}
	}
	set<int>::iterator it;
	
	//cout << "%> cat robdd.dot" << endl;
	/*cout << "digraph ROBDD {" << endl;
	cout <<"	"<<input[0].thisnum << " " << "[label=\"" << input[0].name << "\", shape=box];" << endl;
	for (it=myset.begin();it!=myset.end();it++)
	{
		cout <<"	"<< input[*it].thisnum << " [label=\"" << input[*it].name << "\"]" << endl;
	}
	cout << "	" << input[last].thisnum << " " << "[label=\"" << input[last].name << "\", shape=box];" << endl;
	cout << endl;
	for (it = myset.begin(); it != myset.end(); it++)
	{
		cout <<"	"<< input[*it].thisnum << " -> " << input[*it].next1 << " [label=\"0\", style=dotted]" << endl;
		cout <<"	" <<input[*it].thisnum << " -> " << input[*it].next2 << " [label=\"1\", style=solid]" << endl;
	}
	
	cout << "}" << endl;*/
	//cout <<endl <<"%> dot -T png robdd.dot > output.png " << endl;
	///////////////////////////////p
	char temname[100];
	ofile << "digraph ROBDD {" << endl;
	ofile << "	" << input[0].thisnum << " " << "[label=\"" << input[0].name << "\", shape=box];" << endl;
	for (it = myset.begin(); it != myset.end(); it++)
	{
		ofile << "	" << input[*it].thisnum << " [label=\"" << input[*it].name << "\"]" << endl;
	}
	ofile << "	" << input[last].thisnum << " " << "[label=\"" << input[last].name << "\", shape=box];" << endl;
	ofile << endl;
	for (it = myset.begin(); it != myset.end(); it++)
	{
		ofile << "	" << input[*it].thisnum << " -> " << input[*it].next1 << " [label=\"0\", style=dotted]" << endl;
		ofile << "	" << input[*it].thisnum << " -> " << input[*it].next2 << " [label=\"1\", style=solid]" << endl;
	}

	ofile << "}" << endl;
}
//first judge the right and left are the same->then judge the childern of left and right are the smae of simblings(smae level is ok)
//(00 01 11 10)

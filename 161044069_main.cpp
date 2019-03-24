                              /************************************************/
                              /*                                              */
                              /*                 Osman Çetin                  */
                              /*                  161044069                   */
                              /*                   CSE-241                    */
                              /*                     HW-1                     */
                              /*                                              */ 
                              /*                                              */
                              /************************************************/

/*This program calculates how much small shape fit into big shape with using mathematical calculations. Firstly program asks to user big shape's type(rectangle,cirle,triangle), and type's datas. Secondly asks smallest shape's type and datas. Finally, prepairs output.svg file and calculation results.*/ 



#include <iostream>
#include "source1.h"/*this is program's header file*/

enum shape {rec,circle,tri};/*this enum includes shape types*/
using namespace std;

int main(){

	int k=0;
	char type1,type2;
	double width1,height1,radius1,side1,width2,height2,radius2,side2,result=0;
	shape selection1,selection2;

	while(k==0){/*this takes biggest shape's type and datas from user*/
		cout << "Please enter the main container shape (R, C, T)\n";
		cin >> type1;

		if(type1 == 'R' || type1 == 'r' ){
			selection1=rec;
			cout << "Please enter width:";
			cin >> width1;
			cout << "Please enter height:";
			cin >> height1;
			k++;
		}

		else if(type1 == 'C' || type1 == 'c'){
			selection1=circle;
			cout << "Please enter the radius:";
			cin >> radius1;
			k++;
		}

		else if(type1 == 'T' || type1 == 't'){
			selection1=tri;
			cout << "Please enter the lenght of the edge:";
			cin >> side1;
			k++;
		}

		else{
			cout << "False selection. ";
		}
	}

	k=0;

	while(k==0){/*this takes smallest shape's type and datas from user*/
		cout << "Please enter the small shape (R, C, T)\n";
		cin >> type2;

		if(type2 == 'R' || type2 == 'r' ){
			selection2=rec;
			cout << "Please enter width:";
			cin >> width2;
			cout << "Please enter height:";
			cin >> height2;
			k++;
		}

		else if(type2 == 'C' || type2 == 'c'){
			selection2=circle;
			cout << "Please enter the radius:";
			cin >> radius2;
			k++;
		}

		else if(type2 == 'T' || type2 == 't'){
			selection2=tri;
			cout << "Please enter the edge length:";
			cin >> side2;
			k++;
		}


		else{
			cout << "False selection. ";
		}
	}
	/*This conditions implements proper situation, and takes result from function*/
	if( selection1==rec && selection2==circle){

		result=rec_circle(width1,height1,radius2);

	}

	else if( selection1==rec && selection2==rec){

		result=rec_rec(width1,height1,width2,height2);

	}

	else if( selection1==rec && selection2==tri ){

		result=rec_tri(width1,height1,side2);

	}

	else if( selection1==circle && selection2==circle){

		result=circle_circle(radius1,radius2);

	}

	else if( selection1==tri && selection2==tri){

		result=tri_tri(side1,side2);

	}

	else if( selection1==tri && selection2==rec){

		result=tri_rec(side1,width2,height2);

	}

	else if( selection1==tri && selection2==circle ){

		result=tri_circle(side1,radius2);

	}

	else if( selection1==circle && selection2==rec ){

		result=circle_rec(radius1,width2,height2);

	}

	else if( selection1==circle && selection2==tri){

		result=circle_tri(radius1,side2);

	}

	cout << "The empty area (red) in container is " << result << ".\n";/*this writes result on terminal*/

	return 0;
}

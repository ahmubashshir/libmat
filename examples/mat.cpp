
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 */
#include<iostream>
#define __debug__
#define _limit_ 5
#include <mat.h>
using namespace std;
int main()
{
    int line=7;
	//~ try
	{
	   	unsigned int col,row;
	   	line+=3;
        //cout<<"\n1";
        cout<<"Row:";
	   	line+=3;
        //cout<<"\n2";
        cin>>row;
	   	line+=3;
        //	cout<<"\n3";
        cout<<"Column:";
	   	line+=3;
        //cout<<"\n4";
        cin>>col;
	   	line+=3;
        //	cout<<"\n5";
        line+=4;
        mat <int> mata(row,col,"MatA");
        //cout<<"\n6";
        mat <int> matb(row,col,"MatB");
	   	line+=3;
        //	cout<<"\n7";
        mat <int> ans(row,col,"MatAns");
	   	line+=3;
        //cout<<"\n8";
        mata.in();
	   	line+=3;
        //cout<<"\n9";
        matb.in();
	   	line+=3;
        //cout<<"\n10";
        mata.out();
	   	line+=3;
        //cout<<"\n11";
        matb.out();
	   	line+=3;
        //cout<<"\n12";
        ans.add(mata,matb);
	   	line+=3;
        //cout<<"\n13";
        ans.out();
	   	line+=3;
        //cout<<"\n14";
	}
	//catch(...)
	//{
		//cout<<"Exception Occurred at Line "<<line<<endl;
		//return -3;
	//}
	return 0;
}

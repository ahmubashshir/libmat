
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
    //try
    //{
    unsigned int col,row;
    cout<<"Row:";
    cin>>row;
    cout<<"Column:";
    cin>>col;
    mat <int> mata(row,col,"MatA");
    mat <int> matb(row,col,"MatB");
    mat <int> ans(row,col,"MatAns");
    mata.in();
    matb.in();
    mata.out();
    matb.out();
    ans.add(mata,matb);
    ans.out();
//    }
//    catch(math::error &e)
//    {
//        cout<<"Exception "<<e.id()<<" Occurred at Line "<<line<<endl<<"Description:"<<e.what()<<endl;
//        return e.val;
//    }
//    catch(exception &e)
//    {
//        cout<<"Exception "<<e.what()<<" Occurred at Line "<<line<<endl;
//    }
    return 0;
}

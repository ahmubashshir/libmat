/*
 * target:shared
 *
 * lib.cpp
 * 
 * Copyright <year> Ahmad Hasan Mubashshir <ahmadmubashshir1@gmail.com>
 * 
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
 * 
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstring>
#include <iostream>
#include <exception>
#include "mat.h"
//extern "C" {
//}
extern "C++" {
	template <class T>
	mat<T>::mat(unsigned int row,unsigned int col,const char *name)
	{
		this->dimerr=false;
		this->row=row;this->col=col;this->name=name;
		if(col<=0&&row<=0) exception_handle_buuf;
		if(row>0&&exception_limit) this->ret=new T* [row];
		else exception_handle_2;
		for(unsigned  int i=0;i<row;i++)
		{
			if(col>0)this->ret[i]=new T[col];
			Construct1;
		}
		Construct2;
	}
	template <class T>
	mat<T>::~mat()
	{
		for(unsigned int i=0;i<this->row;i++)
		{
			delete [] this->ret[i];
			Destruct1;
		}
		Destruct2;
	}
	template <class T>
	void mat<T>::in(void)
	{
		std::cout<<std::endl<<"Set "<<this->name<<":"<<std::endl;
		for(unsigned int i=0;i<this->row;i++)
		{
			std::cout<<"Row "<<i<<":";
			for(unsigned int j=0;j<this->col;j++)
			{
						std::cin>>this->ret[i][j];
			}
		}
	}
	template <class T>
	unsigned mat<T>::int_len(long int a)
	{
		long int n=std::abs(a);
		if(n<10) return 1;
		else
		{
			unsigned r=1;
			while(n>=10)
			{
				n/=10;
				r++;
			}
			return r;
		}
	}
	template <class T>
	void mat<T>::add(mat matA,mat matB)
	{
		if((!matA.dimerr)&&(!matB.dimerr))
		{
			if((matA.col==matB.col)&&(matA.row==matB.row)&&(this->col==matA.col)&&(this->row==matA.row))
			{
				for(unsigned int i=0;i<this->row;i++)
				{
					for(unsigned int j=0;j<this->col;j++)
					{
						this->ret[i][j]=matA.ret[i][j]+matB.ret[i][j];
					}
				}
			}
			else
				this->dimerr=true;
		}
		else
			this->dimerr=true;
	}
	template <class T>
	void mat<T>::sub(mat matA,mat matB)
	{
		if((!matA.dimerr)&&(!matB.dimerr))
		{
			if((matA.col==matB.col)&&(matA.row==matB.row)&&(this->col==matA.col)&&(this->row==matA.row))
			{
				for(unsigned int i=0;i<this->row;i++)
				{
					for(unsigned int j=0;j<this->col;j++)
					{
						this->ret[i][j]=matA.ret[i][j]-matB.ret[i][j];
					}
				}
			}
			else
				this->dimerr=true;
		}
		else
			this->dimerr=true;
	}
	template <class T>
	void mat<T>::mul(int multiple)
	{
		if(!this->dimerr)
		{
			for(unsigned int i=0;i<this->row;i++)
				for(unsigned int j=0;j<this->col;j++)
					this->ret[i][j]=multiple*this->ret[i][j];
		}
	}
	template <class T>
	void mat<T>::mul(mat matA,mat matB)
	{
		if((!matA.dimerr)&&(!matB.dimerr))
		{
			if((matA.col==matB.row)&&(this->row==matA.row)&&(this->col==matB.col))
			{
				for(unsigned int i=0;i<this->row;i++)
					for(unsigned int j=0;j<this->col;j++)
						for(unsigned int k=0;k<this->row;k++)
							this->ret[i][j]+=matA.ret[i][k]*matB.ret[k][j];
			}
			else this->dimerr=true;
		}
		else this->dimerr=true;
	}
	template <class T>
	void mat<T>::reinit(unsigned int row,unsigned col,const char* name)
	{
		//Clear::TODO:exception handler
		for(unsigned int i=0;i<this->row;i++)
		{
			delete [] this->ret[i];
			Destruct1;
		}
		Destruct2;
		//Init::TODO:exception handler
		this->dimerr=false;
		this->row=row;this->col=col;this->name=name;
		if(row>0&&exception_limit) this->ret=new T* [row];
		else exception_handle_2;
		for(unsigned  int i=0;i<row;i++)
		{
			if(col>0) this->ret[i]=new T[col];
			else exception_handle_1;
			Construct1;
		}
		Construct2;
	}
	template <class T>
	unsigned mat<T>::get_col(void)
	{
		return this->col;
	}
	template <class T>
	unsigned mat<T>::get_row(void)
	{
		return this->row;
	}
	template <class T>
	T** mat<T>::get_raw(void)
	{
		return this->ret;
	}
	template <class T>
	unsigned mat<T>::get_len(unsigned c)
	{
		unsigned maxlen=0,len=0;
		for(unsigned int i=0;i<row;i++)
		{
			len=int_len((long int)this->ret[i][c]);
			maxlen=(len>=maxlen)?len:maxlen;
		}
		return maxlen;
	}
	template<class T>
	void mat<T>::out(void)
	{
		if(!this->dimerr)
		{
			//if(strlen(op1)>0) std::cout<<op;else
			std::cout<<std::endl<<this->name<<std::endl;
			for(unsigned int i=0;i<this->row;i++)
			{
				for(unsigned int j=0;j<this->col;j++)
				{
					if((this->row==1)&&(j==0)) std::cout<<"[";
					if((this->row>=2)&&(j==0)&&(i==0)) std::cout<<STARTL;
					if((this->row>1)&&(j==0)&&(i!=0)&&(this->row-i!=1)) std::cout<<MIDL;
					if((this->row>=2)&&(j==0)&&(this->row-i==1)) std::cout<<ENDL;
					if((j==0)&&(this->row>1)) std::cout<<" ";
					std::cout<<this->ret[i][j];
					indent
					if((this->row==1)&&(j>=0)&&((this->col-j)>1)) std::cout<<" ";
					if((this->row>=2)&&(j==this->col-1)&&(i==0)) std::cout<<STARTR;
					if((this->row>1)&&(this->col-j==1)&&(i!=0)&&(this->row-i!=1)) std::cout<<MIDR;
					if((this->row>=2)&&(j==this->col-1)&&(this->row-i==1)) std::cout<<ENDR;
					if((j==this->col-1)&&(this->row>1)) std::cout<<"\n";
					if((this->row==1)&&(j==this->col-1)) std::cout<<"]\n";
				}
			}
		} else std::cout<<"Dimension error\n";
	}
	template<>
	void mat<double>::out()
	{
		if(!this->dimerr)
		{
			//if(strlen(op1)>0) std::cout<<op;else
			std::cout<<this->name;
			std::cout<<"\n";
			for(unsigned int i=0;i<this->row;i++)
			{
				for(unsigned int j=0;j<this->col;j++)
				{
					if((this->row==1)&&(j==0)) std::cout<<"[";
					if((this->row>=2)&&(j==0)&&(i==0)) std::cout<<STARTL;
					if((this->row>1)&&(j==0)&&(i!=0)&&(this->row-i!=1)) std::cout<<MIDL;
					if((this->row>=2)&&(j==0)&&(this->row-i==1)) std::cout<<ENDL;
					if((j==0)&&(this->row>1)) std::cout<<" ";
					std::cout<<this->ret[i][j];
					if(get_len(j)==int_len((long int)ret[i][j])) std::cout<<" ";
					else
					{
						unsigned lenmax=get_len(j),len2=int_len((long int)ret[i][j]);
						for(unsigned z=0;z<lenmax-len2+1;z++)
						std::cout<<" ";
					}
					if((this->row==1)&&(j>=0)&&((this->col-j)>1)) std::cout<<" ";
					if((this->row>=2)&&(j==this->col-1)&&(i==0)) std::cout<<STARTR;
					if((this->row>1)&&(this->col-j==1)&&(i!=0)&&(this->row-i!=1)) std::cout<<MIDR;
					if((this->row>=2)&&(j==this->col-1)&&(this->row-i==1)) std::cout<<ENDR;
					if((j==this->col-1)&&(this->row>1)) std::cout<<"\n";
					if((this->row==1)&&(j==this->col-1)) std::cout<<"]";
				}
			}
		} else std::cout<<"Dimension error\n";
	}
	template<>
	void mat<float>::out(void)
	{
		if(!this->dimerr)
		{
			//if(strlen(op1)>0) std::cout<<op;else
			std::cout<<this->name;
			std::cout<<"\n";
			for(unsigned int i=0;i<this->row;i++)
			{
				for(unsigned int j=0;j<this->col;j++)
				{
					if((this->row==1)&&(j==0)) std::cout<<"[";
					if((this->row>=2)&&(j==0)&&(i==0)) std::cout<<STARTL;
					if((this->row>1)&&(j==0)&&(i!=0)&&(this->row-i!=1)) std::cout<<MIDL;
					if((this->row>=2)&&(j==0)&&(this->row-i==1)) std::cout<<ENDL;
					if((j==0)&&(this->row>1)) std::cout<<" ";
					else printf("%.2f",this->ret[i][j]);
					if(get_len(j)==int_len((long int)ret[i][j])) std::cout<<" ";
					else
					{
						unsigned lenmax=get_len(j),len2=int_len((long int)ret[i][j]);
						for(unsigned z=0;z<lenmax-len2+1;z++)
						std::cout<<" ";
					}
					if((this->row==1)&&(j>=0)&&((this->col-j)>1)) std::cout<<" ";
					if((this->row>=2)&&(j==this->col-1)&&(i==0)) std::cout<<STARTR;
					if((this->row>1)&&(this->col-j==1)&&(i!=0)&&(this->row-i!=1)) std::cout<<MIDR;
					if((this->row>=2)&&(j==this->col-1)&&(this->row-i==1)) std::cout<<ENDR;
					if((j==this->col-1)&&(this->row>1)) std::cout<<"\n";
					if((this->row==1)&&(j==this->col-1)) std::cout<<"]";
				}
			}
		} else std::cout<<"Dimension error\n";
	}
	
	
	template class mat<int>;
	template class mat<float>;
	template class mat<double>;
	template class mat<long>;
	template class mat<long long>;
	template class mat<long double>;
	template class mat<short>;
	template class mat<unsigned>;
	template class mat<unsigned short>;
	template class mat<unsigned long>;
	template class mat<unsigned long long>;
}

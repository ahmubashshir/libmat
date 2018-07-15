
/*
 * mat.h
 *
 * Copyright 2018 Ahmad Hasan Mubashshir <ahmubashshir@gmail.com>
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

#ifndef __MATRICS__
#define __MATRICS__
#define __MATRICS_MAGOR__ 3
#define __MATRICS_MINOR__ 4
#ifndef devN
#define devN "\x41\x68\x6D\x61\x64\x20\x48\x61\x73\x61\x6E\x20\x4D\x75\x62\x61\x73\x68\x73\x68\x69\x72"
#endif // devN
#ifndef devC
#define devC "\x50\x6F\x6C\x79\x6D\x61\x74\x68\x20\x54\x65\x61\x6d"
#endif // devC
#if defined(linux) || defined(__gnu_linux__) || defined(__ANDROID__) || defined(__linux__) || defined(__linux) || defined(unix) || defined(__unix) || defined(__unix__) || defined(__APPLE__) || defined(__MACH__) || defined(__FreeBSD__) || defined(__hpux) || defined(_AIX)
	#define STARTL "\342\216\241"
	#define MIDL "\342\216\242"
	#define ENDL "\342\216\243"
	#define STARTR "\342\216\244"
	#define MIDR "\342\216\245"
	#define ENDR "\342\216\246"
#elif defined(_WIN32)||defined(__CYGWIN__)||defined(__MINGW32__)||defined(__MINGW64__)||defined(__WINNT__)
	#define STARTL "\xDA"
	#define MIDL "\xB3"
	#define ENDL "\xC0"
	#define STARTR "\xBF"
	#define MIDR "\xB3"
	#define ENDR "\xD9"
#endif //OS Specific options
#if defined(__debug__)
	#define Destruct1 std::cout<<this->name<<"["<<i<<"] Destructing"<<std::endl
	#define Destruct2 std::cout<<"Destructing "<<this->name<<std::endl;
	#define Construct1 std::cout<<this->name<<"["<<i<<"] Constructing"<<std::endl
	#define Construct2 std::cout<<"Constructing "<<this->name<<std::endl;
#else
	#define Destruct1 std::cout<<""
	#define Destruct2 std::cout<<""
	#define Construct1 std::cout<<""
	#define Construct2 std::cout<<""
#endif // Debug Options
#ifdef _limit_
	#define exception_handle_1 {std::cout<<"Buffer Overflow Error\n";throw col;}
	#define exception_handle_2 {std::cout<<"Buffer Overflow Error\n";throw row;}
	#if _limit_ > 2
		#define exception_limit row<_limit_&&col<_limit_
	#else
		#define exception_limit row<5&&col<5
	#endif
	#define exception_handle_buuf {std::cout<<"Buffer Underflow Error\n";throw row+col;}
#else
	#define exception_limit true
	#define exception_handle_buuf std::cout<<""
	#define exception_handle_1 std::cout<<""
	#define exception_handle_2 std::cout<<""
	//#warning "You should use limited element matrics to protect from buffer overflow by adding the next line"
	//#warning "#define _limit_ <max-index>+1"
#endif // Buffer Limit
#if defined(_noauto)
#define indent if((this->ret[i][j]/100000)>0) std::cout<<" ";\
else if((this->ret[i][j]/10000)>0) std::cout<<"  ";\
else if((this->ret[i][j]/1000)>0) std::cout<<"   ";\
else if((this->ret[i][j]/100)>0) std::cout<<"    ";\
else if((this->ret[i][j]/10)>0) std::cout<<"     ";\
else std::cout<<"      ";
#else
#define indent if(get_len(j)==int_len((long int)ret[i][j])) std::cout<<" ";\
else{unsigned lenmax=get_len(j),len2=int_len((long int)ret[i][j]);for(unsigned z=0;z<lenmax-len2+1;z++) {std::cout<<" ";}}
#endif //Auto Indent
template <class T>
class mat
{
	private:
		unsigned int row,col;
		T** ret;
		const char *name;bool dimerr;char *op1,*op2,*op;
	public:
		/*
		* name: mat::mat()
		* dsc: Constructor
		* @param Row,Col,Name
		* @return None
		* @auto-call:yes
		* @overloaded:no
		*/
		mat(unsigned int row,unsigned int col,const char *name);
		/*
		* name: mat::~mat()
		* dsc: Destructor
		* @param None
		* @return None
		* @auto-call:yes
		* @overloaded:no
		*/
		virtual ~mat();
		/*
		* name: mat::in()
		* dsc: Input function
		* @param None
		* @return None
		* @auto-call:no
		* @overloaded:no
		*/
		virtual void in(void);
		/*
		* name: mat::int_len()
		* dsc: Int length calculator
		* @param Int A
		* @return unsigned length
		* @auto-call: no
		* @overloaded:no
		*/
		virtual unsigned int_len(long int a);
		/*
		* name: mat::out()
		* dsc: Output Function
		* @param None
		* @return None
		* @auto-call: no
		* @overloaded:no
		*/
		virtual void out();
		/*
		* name: mat::add()
		* dsc: T Addition
		* @param Mat A,Mat B
		* @return None
		* @auto-call:no
		* @overloaded:no
		*/
		virtual void add(mat matA,mat matB);
		/*
		* name: mat::sub()
		* dsc: T Subtraction
		* @param Mat A,Mat B
		* @return None
		* @auto-call:no
		* @overloaded:no
		*/
		virtual void sub(mat matA,mat matB);
		/*
		* name: mat::mul()
		* dsc: T Multiplication(Scaler)
		* @param Int Multiple
		* @return None
		* @auto-call:no
		* @overloaded:yes
		*/
		virtual void mul(int multiple);
		/*
		* name:  mat::mul()
		* dsc: T Multiplication(T)
		* @param Mat A,Mat B
		* @return None
		* @auto-call:no
		* @overloaded:yes
		*/
		virtual void mul(mat matA,mat matB);
		/*
		* name: mat::reinit()
		* dsc: Reinitializer
		* @param Row,Col,Name
		* @return None
		* @auto-call:no
		* @overloaded:no
		*/
		virtual void reinit(unsigned int row,unsigned col,const char* name);
		/*
		* name: mat::get_col()
		* dsc: Column
		* @param None
		* @return Column
		* @auto-call:no
		* @overloaded:no
		*/
		virtual unsigned get_col(void);
		/*
		* name: mat::row()
		* dsc: Row
		* @param none
		* @return Row
		* @auto-call:no
		* @overloaded:no
		*/
		virtual unsigned get_row(void);
		/*
		* name: mat::get_raw()
		* dsc: Raw Value
		* @param None
		* @return T Array
		* @auto-call:no
		* @overloaded:no
		*/
		virtual T** get_raw(void);
		/*
		* name: mat::get_len()
		* dsc: Get length
		* @param C
		* @return Length
		* @auto-call:no
		* @overloaded:no
		*/
		virtual unsigned get_len(unsigned c);
};
#endif // __MATRICS__

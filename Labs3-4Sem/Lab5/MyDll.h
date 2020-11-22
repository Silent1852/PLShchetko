#ifndef MY_DLL
#define MY_DLL

#include "string"
#include "fstream"
#include "list"
#include "iostream"
#include "random"
#include "fstream"
#include "list"
#include "ctime"
#include<sstream> 

using namespace std;

namespace Dll{
	
	default_random_engine engine(random_device{}());

	class MD_Class{
	public:
		void Swap(double &a, double &b){
			double c = a;
			a = b;
			b = c;
		}


		/*Matrix and Vector operations*/
							/*Resize*/
		void ArrayResize(double *&Array, int Size){
			Array = (double *)realloc(Array, sizeof(double) * Size);
		}

		void ArrayResize(double **&Array1, int OldSize, int NewSize){
			double **Array = new double*[NewSize];
			for(int i = 0; i < NewSize; i++)
				Array[i] = new double[NewSize];

			for(int i = 0; (i < OldSize) && (i < NewSize); i++)
				for(int j = 0; (j < OldSize) && (j < NewSize); j++)
					Array[i][j] = Array1[i][j];

			for(int i = 0; i < OldSize; i++) delete[]Array1[i];
			delete[]Array1;

			Array1 = Array;
		}

		void ArrayResize(double **&Array1, int OldSize1, int OldSize2, int NewSize1, int NewSize2){
			double **Array = new double*[NewSize1];
			for(int i = 0; i < NewSize1; i++)
				Array[i] = new double[NewSize2];

			for(int i = 0; (i < OldSize1) && (i < NewSize1); i++)
				for(int j = 0; (j < OldSize2) && (j < NewSize2); j++)
					Array[i][j] = Array1[i][j];

			for(int i = 0; i < OldSize1; i++) delete[]Array1[i];
			delete[]Array1;

			Array1 = Array;
		}

		/*Multiplication*/
		void VectorMultiplication(double *Vector1, double *Vector2, double **Array, int Size){
			for(int i = 0; i < Size; i++)
				for(int j = 0; j < Size; j++)
					Array[i][j] = Vector1[i] * Vector2[j];
		}

		void VectorMultiplication(double *Vector, int Size, int Number){
			for(int i = 0; i < Size; i++)
				Vector[i] = Vector[i] * Number;
		}

		void MatrixMultiplication(double **Array, int Size, int Number){
			for(int i = 0; i < Size; i++)
				for(int j = 0; j < Size; j++)
					Array[i][j] = Array[i][j] * Number;
		}

		void MatrixMultiplication(double **Array, int Length1, int Length2, int Number){
			for(int i = 0; i < Length1; i++)
				for(int j = 0; j < Length2; j++)
					Array[i][j] = Array[i][j] * Number;
		}

		void MatrixMultiplication(double **Array1, double **Array2, double **Array3, int Size){
			for(int i = 0; i < Size; i++)
				for(int j = 0; j < Size; j++){
					double sum = 0;
					for(int k = 0; k < Size; k++)
						sum += Array1[i][k] * Array2[k][j];
					Array3[i][j] = sum;
				}
		}

		void MatrixMultiplication(double **Array1, double **Array2, int Size){

			double **Array = new double*[Size];
			for(int i = 0; i < Size; i++)
				Array[i] = new double[Size];

			for(int i = 0; i < Size; i++)
				for(int j = 0; j < Size; j++){
					double sum = 0;
					for(int k = 0; k < Size; k++)
						sum += Array1[i][k] * Array2[k][j];
					Array[i][j] = sum;
				}

			for(int i = 0; i < Size; i++)
				for(int j = 0; j < Size; j++)
					Array1[i][j] = Array[i][j];

			for(int i = 0; i < Size; i++) delete[]Array[i];
			delete[]Array;

		}

		void MatrixMultiplication(double **Array1, double **Array2, double **Array3, int Length1, int Length2){
			for(int i = 0; i < Length1; i++)
				for(int j = 0; j < Length2; j++){
					double sum = 0;
					for(int k = 0; k < Length2; k++)
						sum += Array1[i][k] * Array2[k][j];
					Array3[i][j] = sum;
				}
		}

		void MatrixMultiplication(double **&Array1, double **Array2, int Length1, int Length2){
			if(Length1 == Length2) MatrixMultiplication(Array1, Array2, Length1);
			else{

				double **Array = new double*[Length1];
				for(int i = 0; i < Length1; i++)
					Array[i] = new double[Length1];

				for(int i = 0; i < Length1; i++)
					for(int j = 0; j < Length1; j++){
						double sum = 0;
						for(int k = 0; k < Length2; k++)
							sum += Array1[i][k] * Array2[k][j];
						Array[i][j] = sum;
					}

				ArrayResize(Array1, Length1, Length2, Length1, Length1);

				for(int i = 0; i < Length1; i++)
					for(int j = 0; j < Length1; j++)
						Array1[i][j] = Array[i][j];

				for(int i = 0; i < Length1; i++) delete[]Array[i];
				delete[]Array;
			}
		}

		void MatrixVectorMultiplication(double **Array1, double *Vector1, double *Vector2, int Size){
			for(int j = 0; j < Size; j++)
				for(int i = 0; i < Size; i++)
					Array1[i][j] = Array1[i][j] * Vector1[j];

			ArrayOut(Array1, Size);

			for(int i = 0; i < Size; i++)
				for(int j = 0; j < Size; j++)
					Vector2[i] += Array1[i][j];
		}

		/*Addition */
		void VectorAddition(double *Vector1, double *Vector2, double *Vector3, int Size){
			for(int i = 0; i < Size; i++)
				Vector3[i] = Vector1[i] + Vector2[i];
		}

		void VectorAddition(double *Vector1, double *Vector2, int Size){
			for(int i = 0; i < Size; i++)
				Vector1[i] += Vector2[i];
		}

		void MatrixAddition(double **Array1, double **Array2, double **Array3, int Size){
			for(int i = 0; i < Size; i++)
				for(int j = 0; j < Size; j++)
					Array3[i][j] = Array1[i][j] + Array2[i][j];
		}

		void MatrixAddition(double **Array1, double **Array2, int Size){
			for(int i = 0; i < Size; i++)
				for(int j = 0; j < Size; j++)
					Array1[i][j] += Array2[i][j];
		}

		/*Subtraction */
		void VectorSubtraction(double *Vector1, double *Vector2, double *Vector3, int Size){
			for(int i = 0; i < Size; i++)
				Vector3[i] = Vector1[i] - Vector2[i];
		}

		void VectorSubtraction(double *Vector1, double *Vector2, int Size){
			for(int i = 0; i < Size; i++)
				Vector1[i] -= Vector2[i];
		}

		void MatrixSubtraction(double **Array1, double **Array2, double **Array3, int Size){
			for(int i = 0; i < Size; i++)
				for(int j = 0; j < Size; j++)
					Array3[i][j] = Array1[i][j] - Array2[i][j];
		}

		void MatrixSubtraction(double **Array1, double **Array2, int Size){
			for(int i = 0; i < Size; i++)
				for(int j = 0; j < Size; j++)
					Array1[i][j] -= Array2[i][j];
		}

		/*Transpose */
		void MatrixTranspose(double **Array1, int Size){
			for(int i = 0; i < Size; i++)
				for(int j = 1 + i; j < Size; j++)
					Swap(Array1[i][j], Array1[j][i]);
		}

		void MatrixTranspose(double **Array1, double **Array2, int Length1, int Length2){
			for(int i = 0; i < Length2; i++)
				for(int j = 0; j < Length1; j++)
					Array2[i][j] = Array1[j][i];
		}

		void MatrixTranspose(double **&Array1, int Length1, int Length2){
			double **Array = new double*[Length1];
			for(int i = 0; i < Length1; i++)
				Array[i] = new double[Length2];

			for(int i = 0; i < Length1; i++)
				for(int j = 0; j < Length2; j++)
					Array[i][j] = Array1[i][j];

			ArrayResize(Array1, Length1, Length2, Length2, Length1);

			for(int i = 0; i < Length2; i++)
				for(int j = 0; j < Length1; j++)
					Array1[i][j] = Array[j][i];

			for(int i = 0; i < Length1; i++) delete[]Array[i];
			delete[]Array;
		}


		/*Sorting*/
		void BubbleSort(double *Array, int length){
			for(int i = 0; i < length - 1; i++){
				for(int j = 0; j < length - 1; j++){
					if(Array[j] > Array[j + 1]) Swap(Array[j], Array[j + 1]);
				}
			}
		}

		void BubbleSort(double **Array, int length, std::string SortBy){

			if(SortBy == "Array"){
				int Numb = length * length;
				for(int k = 0; k < Numb - 1; k++){
					for(int i = 0; i < Numb - k - 1; ++i){
						if(Array[i / length][i % length] > (Array[(i + 1) / length][(i + 1) % length]))
							Swap(Array[i / length][i % length], Array[(i + 1) / length][(i + 1) % length]);
					}
				}
			} else if(SortBy == "Line"){
				for(int i = 0; i < length; i++){
					for(int s = 0; s < length - 1; s++){
						for(int j = 0; j < length - 1; j++){
							if(Array[i][j] > Array[i][j + 1]) Swap(Array[i][j], Array[i][j + 1]);
						}
					}
				}
			} else if(SortBy == "Column"){
				for(int i = 0; i < length; i++){
					for(int s = 0; s < length - 1; s++){
						for(int j = 0; j < length - 1; j++){
							if(Array[j][i] > Array[j][i + 1]) Swap(Array[j][i], Array[j][i + 1]);
						}
					}
				}
			}
		}

		void BubbleSort(double **Array, int length1, int length2, std::string SortBy){
			if(SortBy == "Array"){
				int Numb = length1 * length2;
				for(int k = 0; k < Numb - 1; k++){
					for(int i = 0; i < Numb - k - 1; ++i){
						if(Array[i / length2][i % length2] > (Array[(i + 1) / length2][(i + 1) % length2]))
							Swap(Array[i / length2][i % length2], Array[(i + 1) / length2][(i + 1) % length2]);
					}
				}
			} else if(SortBy == "Line"){
				for(int i = 0; i < length1; i++){
					for(int s = 0; s < length2 - 1; s++){
						for(int j = 0; j < length2 - 1; j++){
							if(Array[i][j] > Array[i][j + 1]) Swap(Array[i][j], Array[i][j + 1]);
						}
					}
				}
			} else if(SortBy == "Column"){
				for(int i = 0; i < length1; i++){
					for(int s = 0; s < length2 - 1; s++){
						for(int j = 0; j < length2 - 1; j++){
							if(Array[j][i] > Array[j][i + 1]) Swap(Array[j][i], Array[j][i + 1]);
						}
					}
				}
			}
		}



		/*File*/
		void FileStartPosition(ifstream &UserFile){
			UserFile.clear();
			UserFile.seekg(0);
		}

		bool FileCheckInt(ifstream &UserFile){

			int length = 0;

			if(!UserFile){

				FileStartPosition(UserFile);

				cout << "File not found.\n";
				return 0;
			}

			double N;
			while(UserFile >> N) length++;


			if(length == 0){

				FileStartPosition(UserFile);

				cout << "File empty.\n";
				return 0;
			}

			FileStartPosition(UserFile);
			return 1;
		}

		int FileLengthInt(ifstream &UserFile){
			int length = 0;
			double N;
			while(UserFile >> N) length++;


			if(length == 0) cout << "File empty.\n";

			FileStartPosition(UserFile);

			return length;
		}

		bool FileCheckStr(ifstream &UserFile){

			int length = 0;

			if(!UserFile){

				FileStartPosition(UserFile);

				cout << "File not found.\n";
				return 0;
			}

			char N;
			while(UserFile >> N) length++;


			if(length == 0){

				FileStartPosition(UserFile);

				cout << "File empty.\n";
				return 0;
			}

			FileStartPosition(UserFile);
			return 1;
		}

		int FileLengthStr(ifstream &UserFile){
			int length = 0;
			char N;
			while(UserFile >> N) length++;


			if(length == 0) cout << "File empty.\n";

			FileStartPosition(UserFile);

			return length;
		}



		/*ArrayOut*/
		void ArrayOut(double *Array, int length){
			for(int i = 0; i < length; i++){
				cout.width(3);
				cout << Array[i] << " | ";
			}
			cout << endl;
		}

		void ArrayOut(double **Array, int length){
			for(int i = 0; i < length; i++){
				cout << endl;
				for(int j = 0; j < length; j++){
					cout.width(3);
					cout << Array[i][j] << " | ";
				}
			}
			cout << endl;
		}

		void ArrayOut(double **Array, int length1, int length2){
			for(int i = 0; i < length1; i++){
				cout << endl;
				for(int j = 0; j < length2; j++){
					cout.width(3);
					cout << Array[i][j] << " | ";
				}
			}
			cout << endl;
		}



		/*ArrayInt*/
		void ArrayInt(double *Array, int length){
			for(int i = 0; i < length; i++){
				cin >> Array[i];
			}
		}

		void ArrayInt(double *Array, int length, int RandomStart, int RandomFinish){
			uniform_int_distribution<int> distribut(RandomStart, RandomFinish);
			for(int i = 0; i < length; i++){
				Array[i] = distribut(engine);
			}
		}

		void ArrayInt(double **Array, int length1, int length2){
			for(int i = 0; i < length1; i++){
				for(int j = 0; j < length2; j++){
					cin >> Array[i][j];
				}
			}
		}

		void ArrayInt(double **Array, int length1, int length2, int RandomStart, int RandomFinish){
			uniform_int_distribution<int> distribut(RandomStart, RandomFinish);
			for(int i = 0; i < length1; i++){
				for(int j = 0; j < length2; j++){
					Array[i][j] = distribut(engine);
				}
			}
		}

		void ArrayInt(double **Array, int length){
			for(int i = 0; i < length; i++){
				for(int j = 0; j < length; j++){
					cin >> Array[i][j];
				}
			}
		}

		void ArrayInt(double **Array, int length, int RandomStart, int RandomFinish){
			uniform_int_distribution<int> distribut(RandomStart, RandomFinish);
			for(int i = 0; i < length; i++){
				for(int j = 0; j < length; j++){
					Array[i][j] = distribut(engine);
				}
			}
		}


		/*FileArrayInt*/
		void FileArrayInt(double *Array, int length, ifstream &UserFile){
			if(!FileCheckInt(UserFile)) return;
			double N;
			for(int i = 0; UserFile >> N && i < length; i++){
				Array[i] = N;
			}
			FileStartPosition(UserFile);
		}

		void FileArrayInt(double *Array, ifstream &UserFile){
			if(!FileCheckInt(UserFile)) return;
			double N;
			for(int i = 0; UserFile >> N; i++){
				Array[i] = N;
			}
			FileStartPosition(UserFile);
		}

		void FileArrayInt(double **Array, int length, ifstream &UserFile){
			if(!FileCheckInt(UserFile)) return;
			double N;
			for(int i = 0; i < length; i++){
				for(int j = 0; j < length; j++)
					if(UserFile >> N) Array[i][j] = N;
			}
			FileStartPosition(UserFile);
		}

		void FileArrayInt(double **Array, int length1, int length2, ifstream &UserFile){
			if(!FileCheckInt(UserFile)) return;
			double N;
			for(int i = 0; i < length1; i++){
				for(int j = 0; j < length2; j++)
					if(UserFile >> N) Array[i][j] = N;
			}
			FileStartPosition(UserFile);
		}


		/*Work with text*/
		void ArrayTolower(char * text){
			for(int i = 0; i < strlen(text); i++) text[i] = tolower(text[i]);
		}

		int NumberWordText(std::string text, char Separator){
			int Count = 0;
			bool word = false;

			for(char s : text){
				if((s == Separator || s == '\n') && word){
					Count++;
					word = false;
				} else word = true;
			}

			if(word) return ++Count; else return Count;
		}

		int NumberWordText(std::string text){
			int Count = 0;
			bool word = false;

			for(char s : text){
				if((s == ' ' || s == '\n') && word){
					Count++;
					word = false;
				} else word = true;
			}

			if(word) return ++Count; else return Count;
		}

		int NumberWordFile(ifstream &UserFile){
			int Numb = 0;
			string text;
			while(UserFile >> text) Numb++;

			FileStartPosition(UserFile);

			return Numb;
		}

		int NumbertTextLine(ifstream &UserFile){
			int Numb = 0;
			string text;

			while(std::getline(UserFile, text)) Numb++;

			FileStartPosition(UserFile);

			return Numb;
		}

		std::string GetTextLine(ifstream &UserFile, int NumberLine){
			string text = "";
			int Numb = 1;

			while(std::getline(UserFile, text) && (NumberLine != Numb)) Numb++;

			FileStartPosition(UserFile);

			return text;
		}

		void GetWordText(std::string Text, list<std::string>& ListText, char Separator){
			string TextWord;
			ListText.clear();
			bool word = false;

			for(char s : Text){

				if((s == Separator || s == '\n') && word){
					ListText.push_back(TextWord);
					word = false;
					TextWord = "";
				} else{
					word = true;
					TextWord += s;
				}
			}

			if(word) ListText.push_back(TextWord);
		}

		void GetWordText(std::string Text, list<std::string>& ListText){
			string TextWord;
			ListText.clear();
			bool word = false;

			for(char s : Text){

				if((s == ' ' || s == '\n') && word){
					ListText.push_back(TextWord);
					word = false;
					TextWord = "";
				} else{
					word = true;
					TextWord += s;
				}
			}

			if(word) ListText.push_back(TextWord);
		}

		void GetWordText(std::string Text, std::string *Word, char Separator){
			string TextWord;
			Word->clear();
			bool word = false;
			int Size = NumberWordText(Text, Separator);
			int i = 0;
			for(char s : Text){
				if((s == Separator || s == '\n') && word){
					Word[i] = TextWord;
					++i;
					word = false;
					TextWord = "";
				} else{
					word = true;
					TextWord += s;
				}
			}
	
			if(word) Word[Size - 1] = TextWord;;
		}

		void GetWordText(std::string Text, std::string *Word){
			string TextWord;
			Word->clear();
			bool word = false;
			int Size = NumberWordText(Text);
			int i = 0;
			for(char s : Text){
				if((s == ' ' || s == '\n') && word){
					Word[i] = TextWord;
					++i;
					word = false;
					TextWord = "";
				} else{
					word = true;
					TextWord += s;
				}
			}

			if(word) Word[Size - 1] = TextWord;;
		}

		string TypeVariable(std::string Text){
			if(Text.find_first_not_of("-0123456789") == string::npos && (Text.find_last_of("-") == 0 || Text.find_last_of("-") == string::npos)) return "int";
			else if(Text.find_first_of(".") != 0 && Text.find_last_of(".") != Text.size() - 1 && Text.find_first_not_of("-0123456789.") == string::npos && (Text.find_first_of("123456789") == 0 || Text.find_first_of("123456789") == 1) && Text.find_last_of("0123456789") == Text.size() - 1 && (Text.find_first_of(".") == Text.find_last_of(".")) && (Text.find_last_of("-") == 0 || Text.find_last_of("-") == string::npos)) return "double";
			else return "string";
		}

		string TypeVariable(std::string *Text, int size){
			string Type = "int";
			for(int i = 0; i < size; i++){
				if(TypeVariable(Text[i]) == "string"){
					Type = "string";
					break;
				}else if(TypeVariable(Text[i]) == "double")
					Type = "double";
			}

			return Type;

		}

	};

	class Datetime{
	private:

		int day;
		int month;
		int year;
		int seconds;
		int minutes;
		int hours;

		int daymount[12] = {31,29,31,30,31,30,31,31,30,31,30,31};//Месяца високосного года

		//Проверка на високосный год
		bool leapyear(){
			if((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0))) return true;
			else return false;
		}

		//Проверка на превышение допустимых данных
		bool Excess(){

			bool Error = 0;

			if((day > ((month == 2) ? (daymount[month - 1] - (leapyear() ? 0 : 1)) : daymount[month - 1])) || (day < 1)){
				cout << "Error, exceeding the number of days.\n";
				Error = 1;
			}


			if(month > 12 || month < 1){
				cout << "Error, exceeding the number of mounth.\n";
				Error = 1;
			}

			if(year < 1){
				cout << "Error, exceeding the number of year.\n";
				Error = 1;
			}

			return Error;
		}

		int getdaymonth(int newmonth){
			if(newmonth == 2){
				if(leapyear()){
					if(newmonth - 2 <= 0) return daymount[11 - newmonth - 2];
					else return daymount[newmonth - 2];
				} else{
					if(abs(month) - 1 <= 0) return daymount[11 - newmonth - 2];
					else return daymount[newmonth - 1];
				}
			} else if(newmonth - 1 <= 0) return daymount[11 - newmonth - 2];
			else return daymount[newmonth - 1];
		}

		//Округление данных
		void Rounding(){

			if(seconds >= 60){
				minutes += seconds / 60;
				seconds = seconds % 60;
			} else if(seconds < 0){
				minutes -= seconds / 60;
				seconds = seconds % 60;
				if(seconds < 0){
					seconds = 60 - abs(seconds);
					--minutes;
				}
			}

			if(minutes >= 60){
				hours += minutes / 60;
				minutes = minutes % 60;
				
			} else if(minutes < 0){
				hours -= minutes / 60;
				minutes = minutes % 60;
				if(minutes < 0){
					minutes = 60 - abs(minutes);
					--hours;
				}
			}

			if(hours >= 24){
				day += hours / 24;
				hours = hours % 24;
			} else if(hours < 0){
				day -= hours / 24;
				hours = hours % 24;
				if(hours < 0){
					hours = 24 - abs(hours);
					--day;
				}
			}

			if(month > 12){
				year += month / 12;
				month = month % 12;
			} else if(abs(month) > 12){
				year -= month / 12;
				month = month % 12;
			} else if(month == 0){
				month = 12;
				--year;
			} else if(month < 0){
				month = 12 - month;
				--year;
			}

			while(true){

				if(abs(day) > (366 - (leapyear() ? 0 : 1))){
					if(day > 0){
						day -= (366 - (leapyear() ? 0 : 1));
						++year;
					} else{
						day += (366 - (leapyear() ? 0 : 1));
						--year;
					}
				} else if((abs(day) > getdaymonth(month)) || day < 0){
					if(day > 0){
						day -= getdaymonth(month);
						++month;
					} else if(day < 0){
						day = getdaymonth(month - 1) - abs(day);
						--month;
					} else{
						day += getdaymonth(month - 1);
						--month;
					}

					if(month > 12){
						year += month / 12;
						month = month % 12;
					} else if(abs(month) > 12){
						year -= month / 12;
						month = month % 12;
					} else if(month == 0){
						month = 12;
						--year;
					} else if(month < 0){
						month = 1;
						--year;
					}
				} else break;
			}
		}

		//Перевод в юлианские дни
		int JDN(int day, int month, int year){
			double a, y, m;
			a = abs((14 - month) / 12);
			y = year + 4800 - a;
			m = month + 12 * a - 3;
			return (day + abs((153 * m + 2) / 5) + 365 * y + abs(y / 4) - abs(y / 100) + abs(y / 400) - 32045);
		}

	public:

		Datetime(int newday = 0, int newmonth = 0, int newyear = 0, int newseconds = 0, int newminutes = 0, int newhours = 0){

			struct tm newtime;
			time_t now = time(0);
			localtime_s(&newtime, &now);

			day = newday == 0 ? newtime.tm_mday : newday;
			month = newmonth == 0 ? 1 + newtime.tm_mon : newmonth;
			year = newyear == 0 ? 1900 + newtime.tm_year : newyear;
			seconds = newseconds == 0 ? newtime.tm_sec : newseconds;
			minutes = newminutes == 0 ? newtime.tm_min  : newminutes;
			hours = newhours == 0 ? newtime.tm_hour : newhours;
			
			Excess();
			Rounding();
		}

		void Separation(std::string TextData){

			MD_Class MD;

			string Word[3];

			if(MD.NumberWordText(TextData, '.') == 3){
				MD.GetWordText(TextData, Word, '.');
				settime(stoi(Word[0]), stoi(Word[1]), stoi(Word[2]));
			}
			if(MD.NumberWordText(TextData, '/') == 3){
				MD.GetWordText(TextData, Word, '/');
				settime(stoi(Word[0]), stoi(Word[1]), stoi(Word[2]));
			}

		}

		int getday(){ return day; };
		int getmonth(){ return month; };
		int getyear(){ return year; };
		int getseconds(){ return seconds; };
		int getminutes(){ return minutes; };
		int gethours(){ return hours; };

		void setday(int newday){ day = newday; Rounding(); };
		void setmounth(int newmonth){ month = newmonth; Rounding(); };
		void setyear(int newyear){ year = newyear; Rounding(); };
		void setseconds(int newseconds){ seconds = newseconds; Rounding(); };
		void setminutes(int newminutes){ minutes = newminutes; Rounding(); };
		void sethours(int newhours){ hours = newhours; Rounding(); };

		void settime(int newday = 0, int newmonth = 0, int newyear = 0, int newseconds = 0, int newminutes = 0, int newhours = 0){

			struct tm newtime;
			time_t now = time(0);
			localtime_s(&newtime, &now);

			day = newday == 0 ? newtime.tm_mday : newday;
			month = newmonth == 0 ? 1 + newtime.tm_mon : newmonth;
			year = newyear == 0 ? 1900 + newtime.tm_year : newyear;
			seconds = newseconds == 0 ? newtime.tm_sec : newseconds;
			minutes = newminutes == 0 ? newtime.tm_min : newminutes;
			hours = newhours == 0 ? newtime.tm_hour : newhours;

			Excess();
			Rounding();
		}

		friend void operator++(Datetime a){
			a.setday(a.getday() + 1);
			cout << a;
		}

		friend void operator--(Datetime a){
			a.setday(a.getday() - 1);
			cout << a;
		}

		friend ostream& operator<<(ostream& os, const Datetime& dt){
			os << dt.day << '/' << dt.month << '/' << dt.year << " " << dt.hours << ":" << dt.minutes << ":" << dt.seconds << endl;
			return os;
		}

	};

	


}

#endif
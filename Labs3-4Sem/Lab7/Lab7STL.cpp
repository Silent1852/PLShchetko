#include <iostream>
#include <stack>
#include <string>
#include <list>

using namespace std;

class STL {
private:
	stack<string> stl;
	list<string> ArrAlpha, ArrNumberToAlfa;

	// Проверка на число
	bool TypeIntOrDouble(std::string Text) {
		if (Text == "") return false;
		else if (Text.find_first_not_of("-0123456789") == string::npos && (Text.find_last_of("-") == 0 || Text.find_last_of("-") == string::npos) && Text != "-")return true;
		else if (Text.find_first_of(".") != 0 && Text.find_last_of(".") != Text.size() - 1 && Text.find_first_not_of("-0123456789.") == string::npos && (Text.find_first_of("0123456789") == 0 || Text.find_first_of("0123456789") == 1) && Text.find_last_of("0123456789") == Text.size() - 1 && (Text.find_first_of(".") == Text.find_last_of(".")) && (Text.find_last_of("-") == 0 || Text.find_last_of("-") == string::npos) && Text != "-") {
			return true;
		}
		else return false;
	}

	// Получение копии Stack уменьшенного на 'n' 
	stack<string> StepDown(stack<string> s1, int D) {
		stack<string> s2;
		s2 = s1;
		for (int i = 1; i <= D; i++) s2.pop();
		return s2;
	}


	string Expression(string a, string b, string c) {
		if (c == "+") return to_string(atof(a.c_str()) + atof(b.c_str()));
		if (c == "-") return to_string(atof(a.c_str()) - atof(b.c_str()));
		if (c == "*") return to_string(atof(a.c_str()) * atof(b.c_str()));
		if (c == "/") return to_string(atof(a.c_str()) / atof(b.c_str()));
		return "";
	}

	int Priority(string x) {
		if (x == "+" || x == "-") return 1;
		else if (x == "*" || x == "/") return 2;
		else return -1;
	}

	string Calc(stack<string> s) {

		if (s.size() <= 1) return s.top();
		else {
			if (s.top() == "(") {
				stack<string> s2;
				s.pop();
				int x = 1;
				while (x != 0) {
					if (s.top() == ")") --x;
					else if (s.top() == "(") ++x;
					if (x != 0) s2.push(s.top());
					s.pop();
				}

				s2 = Flip(s2);

				if (s.size() <= 1) return Calc(s2);
				else return Expression(Calc(s2), Calc(StepDown(s, 1)), s.top());

			}
			else if (TypeIntOrDouble(s.top())) {
				if (s.size() > 3) {
					if (StepDown(s, 2).top() == "(") {

						stack<string> s2 = StepDown(s, 3);
						s2.pop();
						int x = 1;
						while (x != 0) {
							if (s2.top() == ")") --x;
							else if (s2.top() == "(") ++x;
							s2.pop();
						}

						if (Priority(StepDown(s, 1).top()) == Priority(s2.top())) {
							s2.push(Expression(s.top(), Calc(StepDown(s, 2)), StepDown(s, 1).top()));
							return Expression(s2.top(), Calc(StepDown(s2, 2)), StepDown(s2, 1).top());
						}
						else if (Priority(StepDown(s, 1).top()) < Priority(s2.top())) {
							return Expression(s.top(), Calc(StepDown(s, 2)), StepDown(s, 1).top());
						}
						else {
							s2.push(Expression(s.top(), Calc(StepDown(s, 2)), StepDown(s, 1).top()));
							return Expression(s2.top(), Calc(StepDown(s2, 2)), StepDown(s2, 1).top());
						}

					}
					else {
						if (Priority(StepDown(s, 1).top()) == Priority(StepDown(s, 3).top()))
							return Expression(s.top(), Calc(StepDown(s, 2)), StepDown(s, 1).top());
						else if (Priority(StepDown(s, 1).top()) < Priority(StepDown(s, 3).top()))
							return Expression(s.top(), Calc(StepDown(s, 2)), StepDown(s, 1).top());
						else {
							stack<string> s2 = s;
							s2 = StepDown(s2, 3);
							s2.push(Expression(s.top(), StepDown(s, 2).top(), StepDown(s, 1).top()));
							return Expression(s2.top(), Calc(StepDown(s2, 2)), StepDown(s2, 1).top());
						}

					}
				}
				else return Expression(s.top(), Calc(StepDown(s, 2)), StepDown(s, 1).top());

			}
		}
	}

public:

	STL(string text) {
		stl = PushString(text, stl);
		if (ArrAlpha.size() != 0) Value();

	}

	void Value() {
		stack<string> x;
		while (!stl.empty()) {
			list<string>::iterator finding = find(ArrAlpha.begin(), ArrAlpha.end(), stl.top());
			list<string>::iterator getindex = ArrNumberToAlfa.begin();
			if (finding != ArrAlpha.end()) {
				stl.pop();
				advance(getindex, distance(ArrAlpha.begin(), finding));
				x.push(*getindex);

			}
			else {
				x.push(stl.top());
				stl.pop();
			}
		}

		stl = Flip(x);

	}

	// Проверка на правильность ввода
	bool Brack() {

		if (stl.empty()) {
			cout << "Empty text.\n";
			return 0;
		}
		else {

			stack<string> a, b, c;
			a = Flip(stl);
			b = StepDown(Flip(stl), 1);
			c = StepDown(Flip(stl), 2);
			if (a.top() == "+" || a.top() == "-" || a.top() == "*" || a.top() == "/") return false;

			while (c.size() != 1) {



				if (TypeIntOrDouble(b.top()))
					if (!(!TypeIntOrDouble(a.top()) && a.top() != ")" && !TypeIntOrDouble(c.top()) && c.top() != "(")) return false;
					else if (b.top() == "(")
						if (!(a.top() != ")" && !TypeIntOrDouble(a.top()) && c.top() != ")" && TypeIntOrDouble(c.top()))) return false;
						else if (b.top() == ")")
							if (!(a.top() != "(" && TypeIntOrDouble(a.top()) && c.top() != "(" && !TypeIntOrDouble(c.top()))) return false;
							else if (b.top() == "+" || b.top() == "-" || b.top() == "*" || b.top() == "/")
								if (!((TypeIntOrDouble(a.top()) || a.top() == ")") && (TypeIntOrDouble(c.top()) || c.top() == "("))) return false;
								else return false;

				a.pop();
				b.pop();
				c.pop();
			}

			stack<string> x, y;
			stack<string> s = stl;
			for (int i = 0, size = s.size(); i < size; i++) {
				if (s.top() == ")" || s.top() == "(") {
					if (x.empty() || s.top() == ")") {
						x.push(s.top());
						s.pop();
					}
					else if (x.top() == ")" && s.top() == "(") {
						x.pop();
						s.pop();
					}
					else s.pop();
				}
				else if (s.top() == "}" || s.top() == "{") {
					if (y.empty() || s.top() == "}") {
						y.push(s.top());
						s.pop();
					}
					else if (y.top() == "}" && s.top() == "{") {
						y.pop();
						s.pop();
					}
					else s.pop();
				}
				else s.pop();
			}
			return x.empty() && y.empty();
		}
	}

	// Запись текста в Stack
	stack<string> PushString(string Text, stack<string> x) {
		string Number = "";
		string alpha = "";

		for (int i = 0; i < Text.length(); i++) {

			if ((i - 1 >= 0) && isalpha(Text[i - 1]) && isalpha(Text[i])) alpha += Text[i];
			else if (isalpha(Text[i])) {
				if (alpha == "") alpha += Text[i];
				else {
					ArrAlpha.push_back(alpha);
					x.push(alpha);
					alpha = "";
					alpha += Text[i];
				}
			}
			else {
				if (alpha != "") {
					ArrAlpha.push_back(alpha);
					x.push(alpha);
					alpha = "";
				}
			}
			switch (Text[i]) {
			case '.':
				if (Number != "" && Number != "-")
					Number += ".";
				break;
			case '-':
				if (x.empty()) {
					if (Number == "") Number += '-';
					else if (Number != "") {
						if (Number.back() == '.')
							Number.pop_back();
						x.push(Number);
						x.push("-");
						Number = "";
					}
				}
				else if (!TypeIntOrDouble(x.top()) && Number == "")
					Number += '-';
				else if (TypeIntOrDouble(x.top())) {
					x.push("-");
					Number = "";
				}
				else if (Number != "") {
					if (Number.back() == '.')
						Number.pop_back();
					x.push(Number);
					x.push("-");
					Number = "";
				}
				break;
			case '0':
				if (Number == "" || Number == "-")
					Number += "0";
				else if ((Number == "-0" || Number == "0") && x.top() == "(") {
					x.push("0");
					Number = "";
				}
				else if (Number != "")
					Number += "0";
				break;
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				Number += Text[i];
				break;
			case '(':
			case ')':
			case '+':
			case '*':
			case '/':
				if (Number != "") {
					if (Number.back() == '.' || Number == "-")
						Number.pop_back();
					else if (Number == "-0")
						Number = "0";
					x.push(Number);
				}
				x.push(string(1, Text[i]));
				Number = "";
				break;
			default:
				break;
			}
			if (i == Text.length() - 1) {
				if (Number != "") {
					if (Number.back() == '.' || Number == "-")
						Number.pop_back();
					else if (Number == "-0")
						Number = "0";
					x.push(Number);
				}
				if (alpha != "") {
					ArrAlpha.push_back(alpha);
					x.push(alpha);
				}
				Number = "";
				alpha = "";
			}
		}
		ArrAlpha.sort();
		ArrAlpha.unique();
		auto iter = ArrAlpha.begin();
		for (int i = 0; i < ArrAlpha.size(); i++, iter++) {
			string number;
			cout << "Enter to '" << *iter << "': ";
			cin >> number;
			if (!TypeIntOrDouble(number)) {
				cout << number << " - this not number.";
				ArrNumberToAlfa.push_back("0");
			}
			else ArrNumberToAlfa.push_back(number);
		}
		return x;
	}

	// Переворот Stack
	stack<string> Flip(stack<string> s1) {
		stack<string> s2;
		for (int i = 0, size = s1.size(); i < size; i++) {
			s2.push(s1.top());
			s1.pop();
		}
		return s2;
	}

	// Вывод Stack
	void Print() {
		stack<string> s2 = Flip(stl);
		for (int i = 0, size = s2.size(); i < size; i++) {
			cout << s2.top();
			s2.pop();
		}
		cout << endl;
	}

	// Вывод результатов вычисление
	void PrintResult() {
		cout << Calc(Flip(stl));
	}
};

int main() {
	string Text = "(B +(23.12-2*A)/(4*2.1-7))*C";
	cout << Text << endl;
	STL stl(Text);
	if (!stl.Brack()) {
		cout << "Error: Not balance brack!\n";
		return 0;
	}
	stl.Print();
	stl.PrintResult();
}
// fig09_52.cpp
// 表达式解析  + - () double 

#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <stdexcept>

// 枚举类型，用于标识 token 的类型
enum obj_type { LP,RP,ADD,SUB,VAL };

struct obj {
	obj(obj_type type, double val = 0) {
		t = type;
		v = val;
	}
	obj_type t;
	double v;
};

//  跳过空格
inline
void skipws(std::string &expr, std::size_t &p) {
	p = expr.find_first_not_of(" ", p);
}

// 遇到数字时候的处理过程 
inline
void new_val(std::stack<obj> &so, double v) {
	if (so.empty() || so.top().t == LP) {
		so.push(obj(VAL, v));
	} else if (so.top().t == ADD || so.top().t = SUB) {
		obj_type type = so.top().t;
		so.pop();
		if (type == ADD)
			v += so.top().v;
		else
			v = so.top().v - v;
		so.pop();
		so.push(obj(VAL, v));
	} else {
		throw std::invalid_argument("缺少运算符号");
	}
}

int main(int argc, char **argv) {
	std::stack<obj> so;
	std::string exp;
	std::size_t p = 0, q;
	double v;
	std::cout << "请输入表达式" << std::endl;
	getline(std::cin, exp);
	while (p < exp.size()) {
		// 跳过空格
		p = skipws(exp, p);
		// 开始处理有效字符
		if (exp[p] = '(') {                            // 遇到'('直接入栈
			so.push(exp[p]);
			p++;
		} else if (exp[p] == '+' || exp[p] == '-') {   // 遇到操作符号
			if (so.empty() || so.top().t != VAL)
				throw std::invalid_argument("缺少运算数据");
			if (exp[p] == '+')
				so.push(obj(ADD));
			else 
				so.push(obj(SUB));
			p++;
		} else if (exp[p] == ')') {                    // 遇到')'
			if (so.empty())
				throw std::invalid_argument("未匹配右括号");
			if (so.top().t == LP)
				throw std::invalid_argument("空括号");
			if (sp.top().t == VAL) {
				v = s.top().v;
				so.pop();
				if (so.empty() || so.top().t != LP) 
					throw std::invalid_argument("未匹配右括号");
				so.pop();
				p++;
				new_val(so, v);
			}
		} else {
			v = stod(exp.substr[p], &q);
			p += q;
			new_val(so, v);
		}
	}
	if (so.size() !=1 || so.top().t != VAL)
		throw std::invalid_argument("非法表达式");
	std::cout << so.top().v << std::endl;
	return 0;
}
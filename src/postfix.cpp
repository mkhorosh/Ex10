// Copyright 2021 mkhorosh
#include "MyStack.h"
#include "postfix.h"

int priority(std::string op) {  // returns operation priority
  if (op == "+" || op == "-")
    return 2;
  if (op == "*" || op == "/")
    return 3;
  return -1;
}

std::string addspaces(std::string infix) {
  std::string ans = {};
  for (int i = 0; i < infix.length(); i++) {
    ans += infix[i];
    if (infix[i] == '(') {
      ans += ' ';
    }
    if (infix[i + 1] == ')') {
      ans += ' ';
    }
  }
  return ans;
}

std::string infix2postfix(std::string infix) {
  infix = addspaces(infix);  // add spaces around ( and ) for valid work
  std::string postfix = {};
  std::string ss = {};
  MyStack<std::string> st(100);
  int i = 0;
  while (i < infix.length()) {
    ss = "";  // substring for current element
    while (infix[i] != ' ' && i < infix.length())  // elements divided by spaces
      ss += infix[i++];
    if (infix[i] == ' ' && ss == "") {
      i++;
      continue;
    }
    if (ss != "" && ss != "(" && ss != ")" && ss != "+" && ss != "-" && ss != "*" && ss != "/") {
      postfix += ss;  // push if operator(not operation)
      postfix += " ";
    } else if (ss == "(") {  // '(' - 0 priority
      st.push(ss);
    } else if (ss == ")") {  // ')' - 1 priority
      // make a postfix
      while (!st.isEmpty() && st.get() != "(") {
        postfix += st.pop();
        postfix += " ";
      }
      if (st.get() == "(") {
        st.pop();
      }
    } else {
      // if operation check the priority and add to postfix if needed
      while (!st.isEmpty() && priority(ss) <= priority(st.get())) {
        postfix += st.pop();
        postfix += " ";
      }
      st.push(ss);
    }
  }
  // add remaining elements from stack
  while (!st.isEmpty()) {
    postfix += st.pop();
    postfix += " ";
  }
  postfix.erase(postfix.end() - 1);  // delete last space
  return postfix;
}

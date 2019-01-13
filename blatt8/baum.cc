#include "fcpp.hh"
#include <string>  // std::string
#include <cstring> // strlen

// zur Unterscheidung von Elementen mit Operatoren und Variablen
char EMPTY_CHAR = ' ';

// zum Zusammenbauen von Strings
std::string convert_int_to_str(int zahl)
{
  char result[16];
  sprintf ( result, "%d", zahl );
  return result;
}

// zum Zusammenbauen von Strings
std::string convert_char_to_str(char zeichen)
{
  return std::string(1, zeichen);
}

struct BaumElement {
  int zahl;
  char variable;
  char zeichen;
  BaumElement* links;
  BaumElement* rechts;
};

BaumElement* create_baumelement(int wert) {
  BaumElement* be = new BaumElement;
  be->zahl = wert;
  be->variable = EMPTY_CHAR;
  be->zeichen = EMPTY_CHAR;
  be->links = 0;
  be->rechts = 0;
  return be;
}
  
BaumElement* create_baumelement(char var) {
  BaumElement* be = new BaumElement;
  be->zahl = 0;
  be->variable = var;
  be->zeichen = EMPTY_CHAR;
  be->links = 0;
  be->rechts = 0;
  return be;
}
  
BaumElement* create_baumelement(char op, BaumElement* l, BaumElement* r) {
  BaumElement* be = new BaumElement;
  be->zahl = 0;
  be->variable = EMPTY_CHAR;
  be->zeichen = op;
  be->links = l;
  be->rechts = r;
  return be;
}
  
std::string print_in(BaumElement* be) {  
  if (be->links && be->rechts) // Elternknoten
  {
    return "(" + print_in(be->links)
      + convert_char_to_str(be->zeichen)
      + print_in(be->rechts) + ")";
  }
  else
  {
    if ( be->variable != EMPTY_CHAR ) // Blattknoten (Variable)
    {
      return convert_char_to_str(be->variable);
    }
    else
    {
      return convert_int_to_str(be->zahl); // Blattknoten (Zahl)
    }
  }
}

std::string print_pre(BaumElement* be) {  
  if (be->links && be->rechts) // Elternknoten
  {
    return convert_char_to_str(be->zeichen)
      + " " + print_pre(be->links)
      + " " +  print_pre(be->rechts);
  }
  else
  {
    if ( be->variable != EMPTY_CHAR ) // Blattknoten (Variable)
    {
      return convert_char_to_str(be->variable);
    }
    else
    {
      return convert_int_to_str(be->zahl); // Blattknoten (Zahl)
    }
  }
}

std::string print_post(BaumElement* be) {  
  if (be->links && be->rechts) // Elternknoten
  {
    return print_post(be->links)
      + " " + print_post(be->rechts)
      + " " + convert_char_to_str(be->zeichen);
  }
  else
  {
    if ( be->variable != EMPTY_CHAR ) // Blattknoten (Variable)
    {
      return convert_char_to_str(be->variable);
    }
    else
    {
      return convert_int_to_str(be->zahl); // Blattknoten (Zahl)
    }
  }
}

BaumElement* insert(BaumElement* expr, char var, BaumElement* subexpr) {
  if (expr==0 || (expr->zeichen == EMPTY_CHAR && expr->variable != var) )
    return expr;
  if (expr->links != 0 &&  expr->rechts != 0)
    return create_baumelement(expr->zeichen,
      insert(expr->links, var, subexpr), insert(expr->rechts, var, subexpr));
  if (expr->variable == var)
    return subexpr;
  return 0;
}

struct Stack
{
  BaumElement* value[100];
  int top;
};

Stack stack;

void init_stack() {
  stack.top = 0;
}

void push(BaumElement* element)
{
  stack.value[stack.top] = element;
  stack.top++;
}

BaumElement* pop()
{
  stack.top--;
  return stack.value[stack.top];
}

bool compose(char op)
{
  if (stack.top < 2)
  {
    std::cout << "Kein valider Ausdruck!";
    return false;
  }

  BaumElement* baum2 = pop();
  BaumElement* baum1 = pop();

  push(create_baumelement( op, baum1, baum2 ));

  return true;
}

BaumElement* create_tree(const char* ausdruck)
{
  init_stack();
  bool leseZahl = false;
  int zahl = 0;
  for (int i = 0; i < strlen(ausdruck); i = i+1)
  {
    char zeichen = ausdruck[i];
    if (zeichen >= '0' && zeichen <= '9')
    {
      leseZahl = true;
      zahl = zahl * 10 + (zeichen - '0');
    }
    else
    {
      if (leseZahl == true)
      {
        push( create_baumelement(zahl) );
        leseZahl = false;
        zahl = 0;
      }

      if (zeichen == '+' || zeichen == '*'
        || zeichen == '/' || zeichen == '-')
      {
          if(!compose(zeichen))
            return 0;
      }

      if ((zeichen >= 'a' && zeichen <= 'z')
        || (zeichen >= 'A' && zeichen <= 'Z'))
      {
        push( create_baumelement(zeichen) );
      }
    }
  }

  BaumElement* be = pop();
  return be;
}

int main (int argc, char* argv[])
{
  const char* ausdruck1 = "67 55 - 54 6 / + 2 *";
  BaumElement* baum1 = create_tree(ausdruck1);

  if(baum1) {
    std::cout << "Praefix: \n" << print_pre(baum1) << std::endl;
    std::cout << "Infix: \n" << print_in(baum1) << std::endl;
    std::cout << "Postfix: \n" << print_post(baum1) << std::endl;
  }

  const char* ausdruck2 = "X 1 - X 1 + *";
  BaumElement* baum2 = create_tree(ausdruck2);

  if(baum2) {
    std::cout << "Praefix: \n" << print_pre(baum2) << std::endl;
    std::cout << "Infix: \n" << print_in(baum2) << std::endl;
    std::cout << "Postfix: \n" << print_post(baum2) << std::endl;
  }

  baum2 = insert(baum2, 'X', baum1);

  if(baum2) {
    std::cout << "Praefix: \n" << print_pre(baum2) << std::endl;
    std::cout << "Infix: \n" << print_in(baum2) << std::endl;
    std::cout << "Postfix: \n" << print_post(baum2) << std::endl;
  }

  return 0;
}

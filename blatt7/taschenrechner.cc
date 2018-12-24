#include"fcpp.hh"
#include<string.h>

struct Stack
{
  int value[100];
  int top;
};

Stack stack;

void push(int element)
{
  stack.value[stack.top] = element;
  stack.top = stack.top + 1;
}

int pop()
{
  stack.top = stack.top - 1;
  return stack.value[stack.top];
}

bool calculate(char operand)
{
  if (stack.top < 2)
  {
    print("Kein valider Ausdruck!");
    return false;
  }

  int zahl1 = pop();
  int zahl2 = pop();
  if (operand == '+')
    push(zahl2 + zahl1);
  else if (operand == '-')
    push(zahl2 - zahl1);
  else if (operand == '*')
    push(zahl2 * zahl1);
  else if (operand == '/')
    push(zahl2 / zahl1);

  return true;
}

int main(int argc, char* argv[])
{
  stack.top = 0;

  char* arg = argv[1];
  bool leseZahl = false;
  int zahl = 0;

  for (int i = 0; i <= strlen(arg); i = i+1)
  {
    char zeichen = arg[i];
    if (zeichen >= '0' && zeichen <= '9')
    {
      leseZahl = true;
      zahl = zahl * 10 + (zeichen - '0');
    }
    else
    {
      if (leseZahl == true)
      {
        push(zahl);
        leseZahl = false;
        zahl = 0;
      }

      if (zeichen == '+' || zeichen == '*' || zeichen == '/' || zeichen == '-')
      {
      if(!calculate(zeichen))
        return false;
      }
    }
  }

  if (leseZahl == true)
  {
    push(zahl);
    leseZahl = false;
    zahl = 0;
  }

  if (stack.top == 1)
  {
    print("Ergebnis:");
    print(pop());
  }
  else
    print ("Kein valider Ausdruck!");

  return true;
}

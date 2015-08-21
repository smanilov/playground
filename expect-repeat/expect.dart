/// Choosing n options uniformly at random, how many do you expect to choose
/// before choosing the same?

import 'dart:io' show
    stdin,
    stdout;

import 'dart:core' show
    int,
    print;

/// Choosing n options uniformly at random, how many do you have to choose,
/// before the probability that you chose at least twice the same option grows
/// above 50%?
int answer1(int n) {
  num prob = 1.0;
  int s = 1;
  while (s <= n && prob > 0.5) {
    prob *= (n-s);
    prob /= n;
    ++s;
  }

  return s;
}

/// Choosing n options uniformly at random, what is the probability that the
/// k-th option is the first one that is a duplicate?
num answer2(int n, int k) {
  num prob = 1.0;
  num answ = 1.0;
  int s = 1;
  while (s < k) {
    answ = prob * s / n;
    prob *= (n-s);
    prob /= n;
    ++s;
  }

  return answ;
}

/// See the original question.
num answer(int n) {
  num prob = 1.0;
  num prob2 = 1.0;
  num expected = 0.0;

  int s = 1;
  while (s <= n) {
    prob2 = prob * s / n;

    prob *= (n-s);
    prob /= n;
    ++s;

    expected += prob2 * s;
  }

  return expected;
  
}

interact() {
  stdout.write("what is n? ");
  int n = int.parse(stdin.readLineSync());
  print("answer1 is ${answer1(n)}");
  print("the answer is ${answer(n)}");
}

main() {
  interact();
}

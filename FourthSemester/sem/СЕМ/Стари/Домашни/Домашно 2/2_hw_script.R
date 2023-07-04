data = rexp(n = 100000, rate = 1/8)

theoremFunc <- function(n, k) {
  vec = c();
  for(i in 1:k) {
    avrNum = mean(sample(x = data, size = n))
    vec <- c(vec, avrNum);
  }
  return (vec);
}

qqnorm(theoremFunc(1000, 500))
qqline(theoremFunc(1000, 500))

#curve(dexp(x, rate = 1/8))

zad2FuncA <- function () {
  param = 25/90
  return (dnbinom(2, 1, param) + dnbinom(3, 1, 0.2666667) + dnbinom(4, 1, 0.2666667) + dnbinom(5, 1, 0.2666667));
}

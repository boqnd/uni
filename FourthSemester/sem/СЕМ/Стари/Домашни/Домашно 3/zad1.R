library(UsingR)

qt(0.05, length(blood) - 1, lower.tail = FALSE)

expert = blood$Expert
machine = blood$Machine

qqnorm(machine)
qqnorm(expert)

t.test(expert, machine, paired = TRUE)
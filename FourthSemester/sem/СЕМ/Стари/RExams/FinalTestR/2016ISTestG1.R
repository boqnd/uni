
##### Zadacha 1
samp_heights=rnorm(500, 172, 20)
A=sample(samp_heights, 100, replace = TRUE)

A[1:5]
summary(A)
hist(A)

sum(A<8)

pnorm(172, mean = 172,sd = 20)
pnorm(182, mean = 172, sd = 20, lower.tail = FALSE)

pnorm(182, mean = 172, sd = 20)-pnorm(172, mean = 172,sd = 20)

qnorm(0.28 + pnorm(172, mean = 172, sd = 20), mean = 172, sd = 20)


##### Zadacha 2
prop.test(5, 25, p = 0.21, alternative = "less")


##### Zadacha 3

samp_men=c(43, 54, 89, 89, 64, 45, 92, 96, 100, 98, 82, 73, 78, 33, 58, 88, 86)
samp_women=c(55, 65, 55, 58, 69, 74, 34, 98, 78, 99, 99, 76, 69, 79, 56, 67, 78, 88, 91, 84, 87, 91)
t.test(samp_men, samp_women, var.equal = T)










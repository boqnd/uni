#Sample 1

#Task 1
height=rnorm(500,172,20)
a=sample(1:500,100,replace=FALSE)
A=height[a]
head(A)
summary(A)
fivenum(A)
hist(A)
sum(A<8)
pnorm(172,172,20)
pnorm(182,172,20,lower.tail = FALSE)
pnorm(182,172,20,lower.tail = FALSE)-pnorm(172,172,20)
qnorm(0.28+pnorm(172,172.20),172,20)

#Task 2
prop.test(5,25,0.21,alternative="less")

#Task 3
men=c(43,54,89,89,64,45,92,96,100,98,82,73,78,33,58,88,86)
women=c(53,65,55,58,69,74,34,98,78,99,99,76,69,79,56,67,78,88,91,84,87,91)
t.test(men,women,var.equal=TRUE)

#Sample 2

#Task 1
arrival=rexp(500,1/12)
a=sample(1:500,100,replace=FALSE)
A=arrival[a]
head(A)
summary(A)
hist(A,probability = TRUE)
sum(A>10)
pexp(12,1/12)
pexp(8,1/12,lower.tail = FALSE)
pexp(12,1/12)-pexp(8,1/12,lower.tail = FALSE)
qexp(0.18+pexp(4,1/12),1/12)

#Sample 3

#Task 1
uniform=runif(500,3,6)
a=sample(1:500,100,replace=FALSE)
A=uniform[a]
head(A)
summary(A)
hist(A,probability = TRUE)
sum(A<12.5)
punif(12.8,3,6)
punif(12.5,3,6)
punif(12.8,3,6)-punif(12.5,3,6)
qunif(0.1+punif(12.5,3,6),3,6)
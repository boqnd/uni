#Sample 1

#Task 1
data=read.csv("D:/Documents/СИ/Материали/СЕМ/RExams/FinalTestR/corns.csv",header = TRUE)
head(data)
summary(data)
table(data$Corns)
prop.table(table(data$Corns))
table(data$state)
prop.table(table(data$state))
hist(table(data$Corns), probability=TRUE,main="Histogram of Corns")
hist(data$Price[data$Corns=="Hazelnuts"], probability=TRUE)
table(data$Corns,data$state)
plot(data$Price[data$state=="Roasted"],data$L[data$state=="Roasted"])
mu=mean(data$L[data$Corns=="Sunflower"])
sd=sd(data$L[data$Corns=="Sunflower"])
ci=c(mu+qnorm(0.04)*sd,mu+qnorm(0.96)*sd)
chisq.test(data$Price,p=dnorm(data$Price,mean(data$Price),sd(data$Price)),rescale.p = TRUE)

#Task 2
pnorm(4,3,1)
pnorm(2,3,1,lower.tail = FALSE)
pnorm(5,3,1)-pnorm(2,3,1)
qnorm(0.9+pnorm(1,3,1),3,1)

#Sample 2

#Task 1
hist(data$W, probability=TRUE,main="Histogram of Weight")
hist(data$Price[data$Corns=="Sunflower"],probability=TRUE)
barplot(table(data$Corns,data$state), beside=T)
plot(data$Price[data$state=="Raw"],data$L[data$state=="Raw"])
mu=mean(data$L[data$Corns=="Pistachios"])
sd=sd(data$L[data$Corns=="Pistachios"])
ci=c(mu+qnorm(0.04)*sd,mu+qnorm(0.96)*sd)
chisq.test(data$W,p=dnorm(data$W,mean(data$W),sd(data$W)),rescale.p = TRUE)

#Task 2
pexp(4,1)
pexp(2,1,lower.tail = FALSE)
pexp(5,1)-pexp(2,1)
qexp(pexp(4,1)-0.9,1)

#Sample 3

#Task 1
hist(data$L, probability=TRUE,main="Histogram of Length")
hist(data$Price[data$Corns=="Walnuts"], probability=TRUE)
boxplot(data$W~data$Corns)
plot(data$Price[data$state=="Dried"],data$L[data$state=="Dried"])
mu=mean(data$W[data$Corns=="Hazelnuts"])
sd=sd(data$W[data$Corns=="Hazelnuts"])
ci=c(mu+qnorm(0.04)*sd,mu+qnorm(0.96)*sd)
chisq.test(data$L,p=dnorm(data$L,mean(data$L),sd(data$L)),rescale.p = TRUE)

#Task 2
pbinom(4,15,0.5)
pbinom(2,15,0.5,lower.tail = FALSE)
pbinom(4,15,0.5)-pbinom(1,15,0.5)
qbinom(0.9+pbinom(1,15,0.5),15,0.5)

#Sample 4

#Task 1
hist(data$Price, probability=TRUE,main="Histogram of Price")
hist(data$Price[data$Corns=="Hazelnuts"], probability=TRUE)
boxplot(data$L~data$Corns)
plot(data$Price[data$Corns=="Almonds"],data$L[data$Corns=="Almonds"])
mu=mean(data$Price)
sd=sd(data$Price)
ci=c(mu+qnorm(0.04)*sd,mu+qnorm(0.96)*sd)
t.test(data$W[data$state=="Dried"],data$W[data$state=="Raw" & data$Corns=="Almonds"],var.equal = TRUE)

#Task 2
ppois(4,3)
ppois(2,3,lower.tail = FALSE)
ppois(4,3)-ppois(1,3)
qpois(ppois(12,3)-0.9,3)

#Sample 5

#Task 1
hist(table(data$state), probability=TRUE,main="Histogram of State")
hist(data$Price[data$Corns=="Almonds"], probability=TRUE)
boxplot(data$Price~data$state)
plot(data$Price[data$Corns=="Pistachios"],data$L[data$Corns=="Pistachios"])
mu=mean(data$Price[data$Corns=="Almonds"])
sd=sd(data$Price[data$Corns=="Almonds"])
ci=c(mu+qnorm(0.04)*sd,mu+qnorm(0.96)*sd)
t.test(data$W[data$state=="Dried"],data$W[data$state=="Raw" & data$Corns=="Hazelnuts"],var.equal = TRUE)

#Task 2
pgeom(4,0.25)
pgeom(2,0.25,lower.tail = FALSE)
pgeom(4,0.25)-pgeom(1,0.25)
qgeom(pgeom(12,0.25)-0.9,0.25)

#Sample 6

#Task 1
hist(table(data$state), probability=TRUE,main="Histogram of State")
hist(data$Price[data$Corns=="=Pistachios"], probability=TRUE)
boxplot(data$Price~data$Corns)
plot(data$Price[data$Corns=="Sunflower"],data$L[data$Corns=="Sunflower"])
mu=mean(data$Price[data$Corns=="Almonds"])
sd=sd(data$Price[data$Corns=="Almonds"])
ci=c(mu+qnorm(0.04)*sd,mu+qnorm(0.96)*sd)
t.test(data$W[data$state=="Dried"],data$W[data$state=="Raw" & data$Corns=="Pistachios"],var.equal = TRUE)

#Task 2
pnbinom(4,3,0.5)
pnbinom(2,3,0.5,lower.tail = FALSE)
pnbinom(4,3,0.5)-pnbinom(1,3,0.5)
qnbinom(pnbinom(12,3,0.5)-0.9,3,0.5)

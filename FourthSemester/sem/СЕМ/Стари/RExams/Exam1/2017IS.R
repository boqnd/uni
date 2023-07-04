#Sample 1

#Task 1
movie=read.csv("D:/Documents/СИ/Материали/СЕМ/RExams/Exam1/movie.csv",header=TRUE)
a=sample(1:3800,3000,replace=FALSE)
m=movie[a,]
names(m)
summary(m)
index=which(m$color=="Color")
m$title_year[index]
index=which(m$color=="Color")
sort(unique(m$title_year[index]))
hist(m$num_voted_users,probability = TRUE)
x=m$country=="Germany"|m$country=="Canada"|m$country=="France"
a=m[x,c("country","color")]
table(a)
barplot(table(a))
boxplot(m$gross~m$color)
mean(m$gross[m$color=="Color"])
mean(m$gross[m$color=="Black and White"])
median(m$gross[m$color=="Color"])
median(m$gross[m$color=="Black and White"])

#Task 2
plot(m$num_user_for_reviews,m$num_voted_users)
l=lm(m$num_voted_users~m$num_user_for_reviews,data=m)
abline(l)
cor(m$num_user_for_reviews,m$num_voted_users)
coef(l)[1]+700000*coef(l)[2]

#Task 3
pgeom(3,4/50)-pgeom(0,4/50)
qnorm(27/50)

#Sample 2

#Task 1
movie=read.csv("D:/Documents/СИ/Материали/СЕМ/RExams/Exam1/movie.csv",header=TRUE)
a=sample(1:3800,3000,replace=FALSE)
m=movie[a,]
names(m)
summary(m)
index=which(m$color=="Black and White")
m$title_year[index]
index=which(m$color=="Black and White")
sort(unique(m$title_year[index]))
hist(m$num_user_for_reviews,probability = TRUE)
x=m$country=="UK"|m$country=="Canada"|m$country=="France"
a=m[x,c("country","color")]
table(a)
barplot(table(a))
boxplot(m$num_voted_users~m$color)
mean(m$num_voted_users[m$color=="Color"])
mean(m$num_voted_users[m$color=="Black and White"])
median(m$num_voted_users[m$color=="Color"])
median(m$num_voted_users[m$color=="Black and White"])

#Task 2
plot(m$num_user_for_reviews,m$num_voted_users)
l=lm(m$num_voted_users~m$num_user_for_reviews,data=m)
abline(l)
cor(m$num_user_for_reviews,m$num_voted_users)
coef(l)[1]+700000*coef(l)[2]

#Task 3
pbinom(3,10,4/50)-pbinom(0,10,4/50)
qt(4/50+pt(-2,2),2)

#Sample 3

#Task 1
movie=read.csv("D:/Documents/СИ/Материали/СЕМ/RExams/Exam1/movie.csv",header=TRUE)
a=sample(1:3800,3000,replace=FALSE)
m=movie[a,]
names(m)
summary(m)
index=which(m$color=="Black and White")
m$title_year[index]
index=which(m$color=="Color")
sort(unique(m$title_year[index]))
hist(m$gross,probability = TRUE)
x=m$country=="UK"|m$country=="Germany"|m$country=="France"
a=m[x,c("country","color")]
table(a)
barplot(table(a))
boxplot(m$num_user_for_reviews~m$color)
mean(m$num_user_for_reviews[m$color=="Color"])
mean(m$num_user_for_reviews[m$color=="Black and White"])
median(m$num_user_for_reviews[m$color=="Color"])
median(m$num_user_for_reviews[m$color=="Black and White"])

#Task 2
plot(m$num_user_for_reviews,m$num_voted_users)
l=lm(m$num_voted_users~m$num_user_for_reviews,data=m)
abline(l)
cor(m$num_user_for_reviews,m$num_voted_users)
coef(l)[1]+700000*coef(l)[2]

#Task 3
ppois(3,2)-ppois(1,2)+ppois(9,2)-ppois(4,2)
qt(4/50+pt(-2,3),3)

#Sample 4

#Task 1
movie=read.csv("D:/Documents/СИ/Материали/СЕМ/RExams/Exam1/movie.csv",header=TRUE)
a=sample(1:3800,3000,replace=FALSE)
m=movie[a,]
names(m)
summary(m)
index=which(m$color=="Color")
m$title_year[index]
index=which(m$color=="Black and White")
sort(unique(m$title_year[index]))
hist(m$duration,probability = TRUE)
x=m$country=="UK"|m$country=="Germany"|m$country=="Canada"
a=m[x,c("country","color")]
table(a)
barplot(table(a))
boxplot(m$duration~m$color)
mean(m$duration[m$color=="Color"])
mean(m$duration[m$color=="Black and White"])
median(m$duration[m$color=="Color"])
median(m$duration[m$color=="Black and White"])

#Task 2
plot(m$num_user_for_reviews,m$num_voted_users)
l=lm(m$num_voted_users~m$num_user_for_reviews,data=m)
abline(l)
cor(m$num_user_for_reviews,m$num_voted_users)
coef(l)[1]+700000*coef(l)[2]

#Task 3
pbinom(4,10,4/50)-pbinom(1,10,4/50)
qnorm(27/50)
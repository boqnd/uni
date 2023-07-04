#EXAM 1 G1

##### Reading from a file:

# simple:
res<-read.csv("movie.csv")

# more specific:
res<-read.csv("movie.csv", header = TRUE, sep = ",", dec = ".", fill = TRUE, blank.lines.skip=TRUE,
              comment.char = "", as.is=TRUE, skipNul=TRUE)

# SEE ?read.csv for all the arguments

##### Converting to data.frame:
res_df=data.frame(res)

##### Samples from the data:
samp_no_rep=sample(c(1:nrow(res_df)), size = 3000, replace = FALSE)
res_df_sub1=res_df[samp_no_rep,]

# Alternative:
samp_no_rep=sample(c(1:nrow(res_df)), size = nrow(res_df), replace = FALSE)
res_df_sub2=res_df[samp_no_rep[c(1:3000)],]

##### Display the variables inside the data.frame and make a summary:
names(res_df)
summary(res_df)

##### First year with Black and White movies:
year_index=which(res_df$color==" Black and White")[1]
res_df$title_year[year_index]

##### Years with Color movies:
year_index=which(res_df$color=="Color")
sort(unique(res_df$title_year[year_index]))


##### Histogram of earnings (gross)
hist(res_df$gross)


##### Barplots and freq tables
filter_countries=res_df$country=="UK" | res_df$country=="France" | res_df$country=="Germany"
res_df_sub=res_df[filter_countries, c("country", "color")]
res_df_sub=subset.data.frame(res_df, country == c("UK", "France", "Germany"), select = c("country", "color"))
res_df_sub = droplevels(res_df_sub)

table(res_df_sub)
table(as.matrix(res_df_sub$country), res_df_sub$color)

barplot(table(res_df_sub), beside = T) 
barplot(table(res_df_sub[,c(2,1)]), beside = T) 


##### Boxplots and violinplots
boxplot(res_df$num_user_for_reviews ~ res_df$color)
violinplot(res_df$num_user_for_reviews ~ res_df$color)


##### meadians and means
mean(res_df$num_user_for_reviews[res_df$color==" Black and White"])
mean(res_df$num_user_for_reviews[res_df$color=="Color"])

median(res_df$num_user_for_reviews[res_df$color==" Black and White"])
median(res_df$num_user_for_reviews[res_df$color=="Color"])

##### Correlattion and linear dependence
filter_countries = res_df$country!="USA"
res_df_sub=res_df[filter_countries, c("num_voted_users", "num_user_for_reviews")]

plot(res_df_sub)
cor(res_df_sub)
lm.result=lm(num_user_for_reviews ~ num_voted_users, data=res_df_sub)
abline(lm.result)

predict(lm.result, data.frame(num_voted_users = 700000))


#### Distributions and quantiles
A=1; B=1; C=1; D=1
ppois(D+3, D+1) - ppois(min(1, D), D+1) + ppois(D+8, D+1) - ppois(D+4, D+1)

qt(p = (A+B+C+D)/50 + pt(-2, D+2), D+2)



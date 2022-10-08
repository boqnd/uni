--моля, изпълнете този скрипт само веднъж.
--базата от данни ще бъде създадена и вие ще започнете да я използвате веднага.
--моля, винаги запазвайте работата ви, след като направите sql изявление или корекция във вашата заявка.

--моля, уверете се, че маркирате, маркирате или изберете вашия конкретен sql израз, преди да го изпълните.

--моля, попълнете следните данни?
-----------------------------------------------------
--1 Пълните имена на студента:
--2 Факултетен номер:
--3 Дата на изпита:
----------------------------------------------------
--Въпрос 5:От следващата таблица напишете SQL заявка, за да изчислите средната заплата на тези служители, които работят като „REVIEWER“. Връщане на средната заплата.

----------------------------------------------------

use master
go
DROP DATABASE IF EXISTS въпрос_5;
go
create database
въпрос_5
go
use въпрос_5
go

------------------------------------------------

--Въпрос 5:От следващата таблица напишете SQL заявка, за да изчислите средната заплата на тези служители, които работят като „REVIEWER“. Връщане на средната заплата.
------------------------------------------------


CREATE TABLE [dbo].[EMPLOYEES](
	[EmployeeID] [float] NULL,
	[LastName] [nvarchar](255) NULL,
	[FirstName] [nvarchar](255) NULL,
	[BirthDate] [nvarchar](255) NULL,
	[Photo] [nvarchar](255) NULL,
	[Notes] [nvarchar](max) NULL,
	[Salary] [float] NULL,
	[Manager] [float] NULL,
	[Location] [nvarchar](255) NULL,
	[Gender] [nvarchar](255) NULL,
	[Position] [nvarchar](255) NULL,
	[dnum] [float] NULL
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO
INSERT [dbo].[EMPLOYEES] ([EmployeeID], [LastName], [FirstName], [BirthDate], [Photo], [Notes], [Salary], [Manager], [Location], [Gender], [Position], [dnum]) VALUES (1, N'Davolio', N'Nancy', N'1968-12-08 00:00:00.000', N'EmpID1.pic', N'Education includes a BA in psychology from Colorado State University. She also completed (The Art of the Cold Call). Nancy is a member of ''Toastmasters International''.', 75000, 2, N'Sofia', N'm', N'ANALYST', 1)
INSERT [dbo].[EMPLOYEES] ([EmployeeID], [LastName], [FirstName], [BirthDate], [Photo], [Notes], [Salary], [Manager], [Location], [Gender], [Position], [dnum]) VALUES (2, N'Fuller', N'Andrew', N'1952-02-19 00:00:00.000', N'EmpID2.pic', N'Andrew received his BTS commercial and a Ph.D. in international marketing from the University of Dallas. He is fluent in French and Italian and reads German. He joined the company as a sales representative, was promoted to sales manager and was then named vice president of sales. Andrew is a member of the Sales Management Roundtable, the Seattle Chamber of Commerce, and the Pacific Rim Importers Association.', 90000, 2, N'Sofia', N'm', N'ANALYST', 1)
INSERT [dbo].[EMPLOYEES] ([EmployeeID], [LastName], [FirstName], [BirthDate], [Photo], [Notes], [Salary], [Manager], [Location], [Gender], [Position], [dnum]) VALUES (3, N'Leverling', N'Janet', N'1963-08-30 00:00:00.000', N'EmpID3.pic', N'Janet has a BS degree in chemistry from Boston College). She has also completed a certificate program in food retailing management. Janet was hired as a sales associate and was promoted to sales representative.', 45000, 2, N'Sofia', N'f', N'ANALYST', 1)
INSERT [dbo].[EMPLOYEES] ([EmployeeID], [LastName], [FirstName], [BirthDate], [Photo], [Notes], [Salary], [Manager], [Location], [Gender], [Position], [dnum]) VALUES (4, N'Peacock', N'Margaret', N'1958-09-19 00:00:00.000', N'EmpID4.pic', N'Margaret holds a BA in English literature from Concordia College and an MA from the American Institute of Culinary Arts. She was temporarily assigned to the London office before returning to her permanent post in Seattle.', 46000, 6, N'Sofia', N'f', N'ANALYST', 1)
INSERT [dbo].[EMPLOYEES] ([EmployeeID], [LastName], [FirstName], [BirthDate], [Photo], [Notes], [Salary], [Manager], [Location], [Gender], [Position], [dnum]) VALUES (5, N'Buchanan', N'Steven', N'1955-03-04 00:00:00.000', N'EmpID5.pic', N'Steven Buchanan graduated from St. Andrews University, Scotland, with a BSC degree. Upon joining the company as a sales representative, he spent 6 months in an orientation program at the Seattle office and then returned to his permanent post in London, where he was promoted to sales manager. Mr. Buchanan has completed the courses ''Successful Telemarketing'' and ''International Sales Management''. He is fluent in French.', 23000, 6, N'Plovdiv', N'm', N'ANALYST', 2)
INSERT [dbo].[EMPLOYEES] ([EmployeeID], [LastName], [FirstName], [BirthDate], [Photo], [Notes], [Salary], [Manager], [Location], [Gender], [Position], [dnum]) VALUES (6, N'Suyama', N'Michael', N'1963-07-02 00:00:00.000', N'EmpID6.pic', N'Michael is a graduate of Sussex University (MA, economics) and the University of California at Los Angeles (MBA, marketing). He has also taken the courses ''Multi-Cultural Selling'' and ''Time Management for the Sales Professional''. He is fluent in Japanese and can read and write French, Portuguese, and Spanish.', 17000, 6, N'Plovdiv', N'm', N'DEVELOPER', 2)
INSERT [dbo].[EMPLOYEES] ([EmployeeID], [LastName], [FirstName], [BirthDate], [Photo], [Notes], [Salary], [Manager], [Location], [Gender], [Position], [dnum]) VALUES (7, N'King', N'Robert', N'1960-05-29 00:00:00.000', N'EmpID7.pic', N'Robert King served in the Peace Corps and traveled extensively before completing his degree in English at the University of Michigan and then joining the company. After completing a course entitled ''Selling in Europe'', he was transferred to the London office.', 6000, 7, N'Plovdiv', N'm', N'DEVELOPER', 2)
INSERT [dbo].[EMPLOYEES] ([EmployeeID], [LastName], [FirstName], [BirthDate], [Photo], [Notes], [Salary], [Manager], [Location], [Gender], [Position], [dnum]) VALUES (8, N'Callahan', N'Laura', N'1958-01-09 00:00:00.000', N'EmpID8.pic', N'Laura received a BA in psychology from the University of Washington. She has also completed a course in business French. She reads and writes French.', 12000, 7, N'Pleven', N'f', N'DEVELOPER', 2)
INSERT [dbo].[EMPLOYEES] ([EmployeeID], [LastName], [FirstName], [BirthDate], [Photo], [Notes], [Salary], [Manager], [Location], [Gender], [Position], [dnum]) VALUES (9, N'Dodsworth', N'Anne', N'1969-07-02 00:00:00.000', N'EmpID9.pic', N'Anne has a BA degree in English from St. Lawrence College. She is fluent in French and German.', 9000, NULL, N'Pleven', N'f', N'DEVELOPER', 3)
INSERT [dbo].[EMPLOYEES] ([EmployeeID], [LastName], [FirstName], [BirthDate], [Photo], [Notes], [Salary], [Manager], [Location], [Gender], [Position], [dnum]) VALUES (10, N'West', N'Adam', N'1928-09-19 00:00:00.000', N'EmpID10.pic', N'An old chum.', 7000, NULL, N'Pleven', N'm', N'DEVELOPER', 3)
INSERT [dbo].[EMPLOYEES] ([EmployeeID], [LastName], [FirstName], [BirthDate], [Photo], [Notes], [Salary], [Manager], [Location], [Gender], [Position], [dnum]) VALUES (11, N'Moore', N'Barry', N'1971-09-19 00:00:00.000', N'EmpID11.pic', N'An old chum.', 75000, NULL, N'Sofia', N'm', N'REVIEWER', 3)
INSERT [dbo].[EMPLOYEES] ([EmployeeID], [LastName], [FirstName], [BirthDate], [Photo], [Notes], [Salary], [Manager], [Location], [Gender], [Position], [dnum]) VALUES (12, N'Brown', N'John', N'1969-11-19 00:00:00.000', N'EmpID12.pic', N'An old chum.', 23000, NULL, N'Sofia', N'm', N'REVIEWER', 3)
INSERT [dbo].[EMPLOYEES] ([EmployeeID], [LastName], [FirstName], [BirthDate], [Photo], [Notes], [Salary], [Manager], [Location], [Gender], [Position], [dnum]) VALUES (13, N'Borisov', N'Boiko', N'1972-04-19 00:00:00.000', N'EmpID13.pic', N'An old chum.', 46000, NULL, N'Sofia', N'm', N'REVIEWER', 1)
INSERT [dbo].[EMPLOYEES] ([EmployeeID], [LastName], [FirstName], [BirthDate], [Photo], [Notes], [Salary], [Manager], [Location], [Gender], [Position], [dnum]) VALUES (14, N'Dominiq', N'Rita', N'1972-01-19 00:00:00.000', N'EmpID14.pic', N'An old chum.', 76000, NULL, N'Sofia', N'f', N'REVIEWER', 2)
INSERT [dbo].[EMPLOYEES] ([EmployeeID], [LastName], [FirstName], [BirthDate], [Photo], [Notes], [Salary], [Manager], [Location], [Gender], [Position], [dnum]) VALUES (15, N'Bravo', N'Donni', N'1972-03-19 00:00:00.000', N'EmpID15.pic', N'An old chum.', 87000, NULL, N'Sofia', N'm', N'REVIEWER', 3)
INSERT [dbo].[EMPLOYEES] ([EmployeeID], [LastName], [FirstName], [BirthDate], [Photo], [Notes], [Salary], [Manager], [Location], [Gender], [Position], [dnum]) VALUES (16, N'Fuller', N'Andrew', N'1967-03-19 00:00:00.000', N'EmpID16.pic', N'An old chum.', 67000, NULL, N'Plovdiv', N'm', N'DEVELOPER', 5)
GO

----------------------------
SELECT *
FROM EMPLOYEES;

----------------------------
--Въпрос 5:От следващата таблица напишете SQL заявка, за да изчислите средната заплата на тези служители, които работят като „REVIEWER“. Връщане на средната заплата.


--------вашето решение------------------


Select AVG(Salary) from EMPLOYEES where Position = 'REVIEWER';


----------------------------------

--след като сте завършили решението, запазете работата си и изпратете обратно този скрипт на инструктора по имейл.
--моля, изпълнете този скрипт само веднъж.
--базата от данни ще бъде създадена и вие ще започнете да я използвате веднага.
--моля, винаги запазвайте работата ви, след като направите sql изявление или корекция във вашата заявка.

--моля, уверете се, че маркирате, маркирате или изберете вашия конкретен sql израз, преди да го изпълните.

--моля, попълнете следните данни?
-----------------------------------------------------
--1 Пълните имена на студента: Ivan Zankov
--2 Факултетен номер: 701335
--3 Дата на изпита: 31.05.2022
----------------------------------------------------
--Въпрос 1:Напишете SQL заявка, за да намерите онези служители, чиято заплата е повече от заплатата на Nancy. Върнете пълна информация за служителите.
----------------------------------------------------

use master
go
DROP DATABASE IF EXISTS въпрос_1;
go
create database
въпрос_1
go
use въпрос_1
go

------------------------------------------------

--Въпрос 1:Напишете SQL заявка, за да намерите онези служители, чиято заплата е повече от заплатата на Nancy. Върнете пълна информация за служителите.

------------------------------------------------


CREATE TABLE [dbo].[DEPARTMENTS](
	[dept_codes] [float] NOT NULL,
	[Departments] [nvarchar](255) NULL,
	[date_created] [nvarchar](255) NULL,
	[Annual budget] [nvarchar](255) NULL,
	[Field5] [nvarchar](255) NULL,
	[manager] [float] NULL
) ON [PRIMARY]
GO

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

SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[PROJECTS](
	[Pname] [nvarchar](255) NULL,
	[Pnumber] [float] NULL,
	[Dnum] [float] NULL,
	[Location] [nvarchar](255) NULL,
	[Type] [nvarchar](255) NULL,
	[Budget] [money] NULL
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[WORK]    Script Date: 25.5.2022 г. 13:32:04 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[WORK](
	[EmployeeID] [float] NULL,
	[Pnumber] [float] NULL,
	[hours] [float] NULL
) ON [PRIMARY]
GO

INSERT [dbo].[EMPLOYEES] ([EmployeeID], [LastName], [FirstName], [BirthDate], [Photo], [Notes], [Salary], [Manager], [Location], [Gender], [Position], [dnum]) VALUES (1, N'Davolio', N'Nancy', N'1968-12-08 00:00:00.000', N'EmpID1.pic', N'Education includes a BA in psychology from Colorado State University. She also completed (The Art of the Cold Call). Nancy is a member of ''Toastmasters International''.', 75000, 1, N'Sofia', N'm', N'ANALYST', 1)
INSERT [dbo].[EMPLOYEES] ([EmployeeID], [LastName], [FirstName], [BirthDate], [Photo], [Notes], [Salary], [Manager], [Location], [Gender], [Position], [dnum]) VALUES (2, N'Fuller', N'Andrew', N'1952-02-19 00:00:00.000', N'EmpID2.pic', N'Andrew received his BTS commercial and a Ph.D. in international marketing from the University of Dallas. He is fluent in French and Italian and reads German. He joined the company as a sales representative, was promoted to sales manager and was then named vice president of sales. Andrew is a member of the Sales Management Roundtable, the Seattle Chamber of Commerce, and the Pacific Rim Importers Association.', 90000, 1, N'Sofia', N'm', N'ANALYST', 1)
INSERT [dbo].[EMPLOYEES] ([EmployeeID], [LastName], [FirstName], [BirthDate], [Photo], [Notes], [Salary], [Manager], [Location], [Gender], [Position], [dnum]) VALUES (3, N'Leverling', N'Janet', N'1963-08-30 00:00:00.000', N'EmpID3.pic', N'Janet has a BS degree in chemistry from Boston College). She has also completed a certificate program in food retailing management. Janet was hired as a sales associate and was promoted to sales representative.', 45000, 1, N'Sofia', N'f', N'ANALYST', 1)
INSERT [dbo].[EMPLOYEES] ([EmployeeID], [LastName], [FirstName], [BirthDate], [Photo], [Notes], [Salary], [Manager], [Location], [Gender], [Position], [dnum]) VALUES (4, N'Peacock', N'Margaret', N'1958-09-19 00:00:00.000', N'EmpID4.pic', N'Margaret holds a BA in English literature from Concordia College and an MA from the American Institute of Culinary Arts. She was temporarily assigned to the London office before returning to her permanent post in Seattle.', 46000, 1, N'Sofia', N'f', N'ANALYST', 1)
INSERT [dbo].[EMPLOYEES] ([EmployeeID], [LastName], [FirstName], [BirthDate], [Photo], [Notes], [Salary], [Manager], [Location], [Gender], [Position], [dnum]) VALUES (5, N'Buchanan', N'Steven', N'1955-03-04 00:00:00.000', N'EmpID5.pic', N'Steven Buchanan graduated from St. Andrews University, Scotland, with a BSC degree. Upon joining the company as a sales representative, he spent 6 months in an orientation program at the Seattle office and then returned to his permanent post in London, where he was promoted to sales manager. Mr. Buchanan has completed the courses ''Successful Telemarketing'' and ''International Sales Management''. He is fluent in French.', 23000, 1, N'Plovdiv', N'm', N'ANALYST', 2)
INSERT [dbo].[EMPLOYEES] ([EmployeeID], [LastName], [FirstName], [BirthDate], [Photo], [Notes], [Salary], [Manager], [Location], [Gender], [Position], [dnum]) VALUES (6, N'Suyama', N'Michael', N'1963-07-02 00:00:00.000', N'EmpID6.pic', N'Michael is a graduate of Sussex University (MA, economics) and the University of California at Los Angeles (MBA, marketing). He has also taken the courses ''Multi-Cultural Selling'' and ''Time Management for the Sales Professional''. He is fluent in Japanese and can read and write French, Portuguese, and Spanish.', 17000, 6, N'Plovdiv', N'm', N'DEVELOPER', 2)
INSERT [dbo].[EMPLOYEES] ([EmployeeID], [LastName], [FirstName], [BirthDate], [Photo], [Notes], [Salary], [Manager], [Location], [Gender], [Position], [dnum]) VALUES (7, N'King', N'Robert', N'1960-05-29 00:00:00.000', N'EmpID7.pic', N'Robert King served in the Peace Corps and traveled extensively before completing his degree in English at the University of Michigan and then joining the company. After completing a course entitled ''Selling in Europe'', he was transferred to the London office.', 6000, 6, N'Plovdiv', N'm', N'DEVELOPER', 2)
INSERT [dbo].[EMPLOYEES] ([EmployeeID], [LastName], [FirstName], [BirthDate], [Photo], [Notes], [Salary], [Manager], [Location], [Gender], [Position], [dnum]) VALUES (8, N'Callahan', N'Laura', N'1958-01-09 00:00:00.000', N'EmpID8.pic', N'Laura received a BA in psychology from the University of Washington. She has also completed a course in business French. She reads and writes French.', 12000, 6, N'Pleven', N'f', N'DEVELOPER', 2)
INSERT [dbo].[EMPLOYEES] ([EmployeeID], [LastName], [FirstName], [BirthDate], [Photo], [Notes], [Salary], [Manager], [Location], [Gender], [Position], [dnum]) VALUES (9, N'Dodsworth', N'Anne', N'1969-07-02 00:00:00.000', N'EmpID9.pic', N'Anne has a BA degree in English from St. Lawrence College. She is fluent in French and German.', 9000, 6, N'Pleven', N'f', N'DEVELOPER', 3)
INSERT [dbo].[EMPLOYEES] ([EmployeeID], [LastName], [FirstName], [BirthDate], [Photo], [Notes], [Salary], [Manager], [Location], [Gender], [Position], [dnum]) VALUES (10, N'West', N'Adam', N'1928-09-19 00:00:00.000', N'EmpID10.pic', N'An old chum.', 7000, 6, N'Pleven', N'm', N'DEVELOPER', 3)
INSERT [dbo].[EMPLOYEES] ([EmployeeID], [LastName], [FirstName], [BirthDate], [Photo], [Notes], [Salary], [Manager], [Location], [Gender], [Position], [dnum]) VALUES (11, N'Moore', N'Barry', N'1971-09-19 00:00:00.000', N'EmpID11.pic', N'An old chum.', 75000, 11, N'Sofia', N'm', N'REVIEWER', 3)
INSERT [dbo].[EMPLOYEES] ([EmployeeID], [LastName], [FirstName], [BirthDate], [Photo], [Notes], [Salary], [Manager], [Location], [Gender], [Position], [dnum]) VALUES (12, N'Brown', N'John', N'1969-11-19 00:00:00.000', N'EmpID12.pic', N'An old chum.', 23000, 12, N'Sofia', N'm', N'REVIEWER', 3)
INSERT [dbo].[EMPLOYEES] ([EmployeeID], [LastName], [FirstName], [BirthDate], [Photo], [Notes], [Salary], [Manager], [Location], [Gender], [Position], [dnum]) VALUES (13, N'Borisov', N'Boiko', N'1972-04-19 00:00:00.000', N'EmpID13.pic', N'An old chum.', 46000, 11, N'Sofia', N'm', N'REVIEWER', 1)
INSERT [dbo].[EMPLOYEES] ([EmployeeID], [LastName], [FirstName], [BirthDate], [Photo], [Notes], [Salary], [Manager], [Location], [Gender], [Position], [dnum]) VALUES (14, N'Dominiq', N'Rita', N'1972-01-19 00:00:00.000', N'EmpID14.pic', N'An old chum.', 76000, 11, N'Sofia', N'f', N'REVIEWER', 2)
INSERT [dbo].[EMPLOYEES] ([EmployeeID], [LastName], [FirstName], [BirthDate], [Photo], [Notes], [Salary], [Manager], [Location], [Gender], [Position], [dnum]) VALUES (15, N'Bravo', N'Donni', N'1972-03-19 00:00:00.000', N'EmpID15.pic', N'An old chum.', 87000, 11, N'Sofia', N'm', N'REVIEWER', 3)
INSERT [dbo].[EMPLOYEES] ([EmployeeID], [LastName], [FirstName], [BirthDate], [Photo], [Notes], [Salary], [Manager], [Location], [Gender], [Position], [dnum]) VALUES (16, N'Fuller', N'Andrew', N'1967-03-19 00:00:00.000', N'EmpID16.pic', N'An old chum.', 67000, 11, N'Plovdiv', N'm', N'DEVELOPER', 5)
GO
INSERT [dbo].[PROJECTS] ([Pname], [Pnumber], [Dnum], [Location], [Type], [Budget]) VALUES (N'Durango', 1, 1, N'Plovdiv', N'spaceflight ', 45000000.0000)
INSERT [dbo].[PROJECTS] ([Pname], [Pnumber], [Dnum], [Location], [Type], [Budget]) VALUES (N'MadMatrix', 2, 1, N'Plovdiv', N'Science ', 35000000.0000)
INSERT [dbo].[PROJECTS] ([Pname], [Pnumber], [Dnum], [Location], [Type], [Budget]) VALUES (N'Othello', 3, 1, N'Plovdiv', N'Science ', 65000000.0000)
INSERT [dbo].[PROJECTS] ([Pname], [Pnumber], [Dnum], [Location], [Type], [Budget]) VALUES (N'Cowbelles', 4, 1, N'Plovdiv', N'Science ', 78000000.0000)
INSERT [dbo].[PROJECTS] ([Pname], [Pnumber], [Dnum], [Location], [Type], [Budget]) VALUES (N'Sunergy', 5, 2, N'Plovdiv', N'Science ', 98000000.0000)
INSERT [dbo].[PROJECTS] ([Pname], [Pnumber], [Dnum], [Location], [Type], [Budget]) VALUES (N'Colossus', 6, 2, N'Plovdiv', N'Science ', 120000000.0000)
INSERT [dbo].[PROJECTS] ([Pname], [Pnumber], [Dnum], [Location], [Type], [Budget]) VALUES (N'Bladerunner', 7, 2, N'Sofia', N'Science ', 89000000.0000)
INSERT [dbo].[PROJECTS] ([Pname], [Pnumber], [Dnum], [Location], [Type], [Budget]) VALUES (N'Bast', 8, 2, N'Sofia', N'Science ', 67000000.0000)
INSERT [dbo].[PROJECTS] ([Pname], [Pnumber], [Dnum], [Location], [Type], [Budget]) VALUES (N'Darwin', 9, 3, N'Sofia', N'Science ', 55000000.0000)
INSERT [dbo].[PROJECTS] ([Pname], [Pnumber], [Dnum], [Location], [Type], [Budget]) VALUES (N'Westerners', 10, 3, N'Sofia', N'Infrastructure', 28000000.0000)
INSERT [dbo].[PROJECTS] ([Pname], [Pnumber], [Dnum], [Location], [Type], [Budget]) VALUES (N'Dagwood', 11, 3, N'Sofia', N'Infrastructure', 150000000.0000)
INSERT [dbo].[PROJECTS] ([Pname], [Pnumber], [Dnum], [Location], [Type], [Budget]) VALUES (N'Bongo', 12, 3, N'Sofia', N'Infrastructure', 89000000.0000)
INSERT [dbo].[PROJECTS] ([Pname], [Pnumber], [Dnum], [Location], [Type], [Budget]) VALUES (N'Yorick', 13, NULL, N'Sofia', N'spaceflight ', 94000000.0000)
GO
INSERT [dbo].[WORK] ([EmployeeID], [Pnumber], [hours]) VALUES (9, 9, 10)
INSERT [dbo].[WORK] ([EmployeeID], [Pnumber], [hours]) VALUES (10, 10, 20)
INSERT [dbo].[WORK] ([EmployeeID], [Pnumber], [hours]) VALUES (11, 11, 25)
INSERT [dbo].[WORK] ([EmployeeID], [Pnumber], [hours]) VALUES (16, 12, 30)
INSERT [dbo].[WORK] ([EmployeeID], [Pnumber], [hours]) VALUES (1, 1, 10)
INSERT [dbo].[WORK] ([EmployeeID], [Pnumber], [hours]) VALUES (1, 2, 20)
INSERT [dbo].[WORK] ([EmployeeID], [Pnumber], [hours]) VALUES (1, 3, 25)
INSERT [dbo].[WORK] ([EmployeeID], [Pnumber], [hours]) VALUES (1, 4, 30)
INSERT [dbo].[WORK] ([EmployeeID], [Pnumber], [hours]) VALUES (4, 1, 17)
INSERT [dbo].[WORK] ([EmployeeID], [Pnumber], [hours]) VALUES (4, 2, 23)
INSERT [dbo].[WORK] ([EmployeeID], [Pnumber], [hours]) VALUES (4, 3, 10)
INSERT [dbo].[WORK] ([EmployeeID], [Pnumber], [hours]) VALUES (4, 4, 20)
INSERT [dbo].[WORK] ([EmployeeID], [Pnumber], [hours]) VALUES (3, 1, 25)
INSERT [dbo].[WORK] ([EmployeeID], [Pnumber], [hours]) VALUES (3, 2, 30)
INSERT [dbo].[WORK] ([EmployeeID], [Pnumber], [hours]) VALUES (2, 3, 17)
INSERT [dbo].[WORK] ([EmployeeID], [Pnumber], [hours]) VALUES (2, 4, 23)
INSERT [dbo].[WORK] ([EmployeeID], [Pnumber], [hours]) VALUES (11, 2, 10)
INSERT [dbo].[WORK] ([EmployeeID], [Pnumber], [hours]) VALUES (12, 3, 20)
INSERT [dbo].[WORK] ([EmployeeID], [Pnumber], [hours]) VALUES (13, 4, 20)
INSERT [dbo].[WORK] ([EmployeeID], [Pnumber], [hours]) VALUES (5, 5, 30)
INSERT [dbo].[WORK] ([EmployeeID], [Pnumber], [hours]) VALUES (5, 6, 40)
INSERT [dbo].[WORK] ([EmployeeID], [Pnumber], [hours]) VALUES (5, 7, 25)
INSERT [dbo].[WORK] ([EmployeeID], [Pnumber], [hours]) VALUES (5, 8, 12)
INSERT [dbo].[WORK] ([EmployeeID], [Pnumber], [hours]) VALUES (6, 5, 8)
INSERT [dbo].[WORK] ([EmployeeID], [Pnumber], [hours]) VALUES (6, 6, 14)
INSERT [dbo].[WORK] ([EmployeeID], [Pnumber], [hours]) VALUES (6, 7, 27)
INSERT [dbo].[WORK] ([EmployeeID], [Pnumber], [hours]) VALUES (6, 8, 33)
INSERT [dbo].[WORK] ([EmployeeID], [Pnumber], [hours]) VALUES (7, 5, 12)
INSERT [dbo].[WORK] ([EmployeeID], [Pnumber], [hours]) VALUES (7, 6, 11)
INSERT [dbo].[WORK] ([EmployeeID], [Pnumber], [hours]) VALUES (8, 7, NULL)
INSERT [dbo].[WORK] ([EmployeeID], [Pnumber], [hours]) VALUES (8, 8, NULL)
INSERT [dbo].[WORK] ([EmployeeID], [Pnumber], [hours]) VALUES (14, 8, NULL)
GO
INSERT [dbo].[DEPARTMENTS] ([dept_codes], [Departments], [date_created], [Annual budget], [Field5], [manager]) VALUES (1, N'Treasury', N'September 2, 1789', NULL, N'$16.55 billion', 1)
INSERT [dbo].[DEPARTMENTS] ([dept_codes], [Departments], [date_created], [Annual budget], [Field5], [manager]) VALUES (2, N'Defense', N'September 18, 1947', NULL, N'$716 billion', 6)
INSERT [dbo].[DEPARTMENTS] ([dept_codes], [Departments], [date_created], [Annual budget], [Field5], [manager]) VALUES (3, N'Justice', N'July 1, 1870', NULL, N'$33.2 billion', 11)
INSERT [dbo].[DEPARTMENTS] ([dept_codes], [Departments], [date_created], [Annual budget], [Field5], [manager]) VALUES (4, N'Interior', N'March 3, 1849', NULL, N'$21.55 billion', 12)
INSERT [dbo].[DEPARTMENTS] ([dept_codes], [Departments], [date_created], [Annual budget], [Field5], [manager]) VALUES (5, N'Agriculture', N'May 15, 1862', N'1,51e+11', N'$151 billion', NULL)
INSERT [dbo].[DEPARTMENTS] ([dept_codes], [Departments], [date_created], [Annual budget], [Field5], [manager]) VALUES (6, N'Commerce', N'February 14, 1903', NULL, N'$7.89 billion', NULL)
INSERT [dbo].[DEPARTMENTS] ([dept_codes], [Departments], [date_created], [Annual budget], [Field5], [manager]) VALUES (7, N'Labor', N'March 4, 1913', NULL, N'$41.7 billion', NULL)
INSERT [dbo].[DEPARTMENTS] ([dept_codes], [Departments], [date_created], [Annual budget], [Field5], [manager]) VALUES (8, N'Health and Human Services', N'April 11, 1953', NULL, N'$1.394 trillion', NULL)
INSERT [dbo].[DEPARTMENTS] ([dept_codes], [Departments], [date_created], [Annual budget], [Field5], [manager]) VALUES (9, N'Education', N'October 17, 1979', NULL, N'$72.3 billion', NULL)
GO

----------------------------
SELECT *
FROM PROJECTS;
SELECT *
FROM DEPARTMENTS;
----------------------------
--Въпрос 1:Напишете SQL заявка, за да намерите онези служители, чиято заплата е повече от заплатата на Nancy. Върнете пълна информация за служителите.

----------------------------------------------------------------------


--------вашето решение--------------------
SELECT *
FROM employees
WHERE salary > (SELECT salary
     FROM employees
     WHERE FirstName = 'Nancy');
----------------------------------

--след като сте завършили решението, запазете работата си и изпратете обратно този скрипт на инструктора по имейл.
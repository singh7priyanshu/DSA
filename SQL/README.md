# Leetcode SQL
**[595. Big Countries](https://leetcode.com/problems/big-countries/)**<br />
Table: `World`
<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| name        | varchar |
| continent   | varchar |
| area        | int     |
| population  | int     |
| gdp         | int     |
+-------------+---------+
name is the primary key column for this table.
Each row of this table gives information about the name of a country, the continent to which it belongs, its area, the population, and its GDP value.
</pre>

A country is **big** if:<br />
 * it has an area of at least three million (i.e., `3000000 km^2`), or<br />
 * it has a population of at least twenty-five million (i.e., `25000000`).<br />
Write an SQL query to report the name, population, and area of the **big countries**.<br />

Return the result table in `any order`.<br />

The query result format is in the following example.<br />

>Example 1:<br />
<pre>
Input: 
World table:
+-------------+-----------+---------+------------+--------------+
| name        | continent | area    | population | gdp          |
+-------------+-----------+---------+------------+--------------+
| Afghanistan | Asia      | 652230  | 25500100   | 20343000000  |
| Albania     | Europe    | 28748   | 2831741    | 12960000000  |
| Algeria     | Africa    | 2381741 | 37100000   | 188681000000 |
| Andorra     | Europe    | 468     | 78115      | 3712000000   |
| Angola      | Africa    | 1246700 | 20609294   | 100990000000 |
+-------------+-----------+---------+------------+--------------+
Output: 
+-------------+------------+---------+
| name        | population | area    |
+-------------+------------+---------+
| Afghanistan | 25500100   | 652230  |
| Algeria     | 37100000   | 2381741 |
+-------------+------------+---------+
</pre>

```sql
-- simple method
select name, population, area 
from World 
where area >= 3000000 or population >= 25000000

-- using union 
select name, population, area 
from World 
where area >= 3000000

union

select name, population, area 
from World 
where population >= 25000000
```

<br /> <br /> <br /> **[1757. Recyclable and Low Fat Products](https://leetcode.com/problems/recyclable-and-low-fat-products/)**<br />
Table: `Products`<br />
<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| product_id  | int     |
| low_fats    | enum    |
| recyclable  | enum    |
+-------------+---------+
product_id is the primary key for this table.
low_fats is an ENUM of type ('Y', 'N') where 'Y' means this product is low fat and 'N' means it is not.
recyclable is an ENUM of types ('Y', 'N') where 'Y' means this product is recyclable and 'N' means it is not.
</pre>
Write an SQL query to find the ids of products that are both low fat and recyclable.<br />

Return the result table in **any order**.<br />

The query result format is in the following example.<br /> 

>Example 1:<br />
<pre>
Input: 
Products table:
+-------------+----------+------------+
| product_id  | low_fats | recyclable |
+-------------+----------+------------+
| 0           | Y        | N          |
| 1           | Y        | Y          |
| 2           | N        | Y          |
| 3           | Y        | Y          |
| 4           | N        | N          |
+-------------+----------+------------+
Output: 
+-------------+
| product_id  |
+-------------+
| 1           |
| 3           |
+-------------+
Explanation: Only products 1 and 3 are both low fat and recyclable.
</pre>

```sql
select product_id 
from Products 
where low_fats = 'Y' and recyclable = 'Y'
```




<br /> <br /> <br /> **[584. Find Customer Referee](https://leetcode.com/problems/find-customer-referee/)**<br />
Table: `Customer`<br />
<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
| referee_id  | int     |
+-------------+---------+
id is the primary key column for this table.
Each row of this table indicates the id of a customer, their name, and the id of the customer who referred them.
</pre>
Write an SQL query to report the names of the customer that are **not referred by** the customer with `id = 2`.<br />
Return the result table in `any order`.<br />
The query result format is in the following example.<br />

>Example 1:<br />
<pre>
Input: 
Customer table:
+----+------+------------+
| id | name | referee_id |
+----+------+------------+
| 1  | Will | null       |
| 2  | Jane | null       |
| 3  | Alex | 2          |
| 4  | Bill | null       |
| 5  | Zack | 1          |
| 6  | Mark | 2          |
+----+------+------------+
Output: 
+------+
| name |
+------+
| Will |
| Jane |
| Bill |
| Zack |
+------+
</pre>

```sql
select name 
from Customer
where referee_id != '2' OR referee_id is NULL

-- most efficient
-- The IFNULL() function returns a specified value if the expression is NULL. If the expression is NOT NULL, this function returns the expression.
select name 
from Customer 
where INFULL(referee_id, 0) <> 2

-- using COALESCE function
-- The COALESCE() function returns the first non-null value in a list.
select name 
from Customer 
where COALESCE(referee_id, 0) <> 2

-- using nested query 
select name 
from Customer 
where id NOT IN (
    select id 
    from Customer 
    where referee_id = 2
    )
```





<br /> <br /> <br /> **[183. Customers Who Never Order](https://leetcode.com/problems/customers-who-never-order/)**<br />
Table: `Customers`<br />
<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
+-------------+---------+
id is the primary key column for this table.
Each row of this table indicates the ID and name of a customer.
</pre>
Table: `Orders`<br />
<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| id          | int  |
| customerId  | int  |
+-------------+------+
id is the primary key column for this table.
customerId is a foreign key of the ID from the Customers table.
Each row of this table indicates the ID of an order and the ID of the customer who ordered it.
</pre>
Write an SQL query to report all customers who never order anything.<br />
Return the result table in **any order**.<br />
The query result format is in the following example.<br />
>Example 1:<br />
<pre>
Input: 
Customers table:
+----+-------+
| id | name  |
+----+-------+
| 1  | Joe   |
| 2  | Henry |
| 3  | Sam   |
| 4  | Max   |
+----+-------+
Orders table:
+----+------------+
| id | customerId |
+----+------------+
| 1  | 3          |
| 2  | 1          |
+----+------------+
Output: 
+-----------+
| Customers |
+-----------+
| Henry     |
| Max       |
+-----------+
</pre>

```sql
-- using left join 
SELECT name as Customers FROM Customers c 
        LEFT JOIN Orders o
            ON c.id = o.customerId
                WHERE o.customerId IS NULL;

-- using not in 
SELECT name as Customers FROM Customers WHERE id not in (SELECT customerId FROM Orders);
```








<br /> <br /> <br /> **[1873. Calculate Special Bonus](https://leetcode.com/problems/calculate-special-bonus/)**<br />
Table: `Employees`<br />
<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| employee_id | int     |
| name        | varchar |
| salary      | int     |
+-------------+---------+
employee_id is the primary key for this table.
Each row of this table indicates the employee ID, employee name, and salary.
</pre>
Write an SQL query to calculate the bonus of each employee. The bonus of an employee is `100%` of their salary if the ID of the employee is **an odd number** and **the employee name does not start with the character** `'M'`. The bonus of an employee is `0` otherwise.<br />
Return the result table ordered by `employee_id`.<br />
The query result format is in the following example.<br />

>Example 1:<br />
<pre>
Input: 
Employees table:
+-------------+---------+--------+
| employee_id | name    | salary |
+-------------+---------+--------+
| 2           | Meir    | 3000   |
| 3           | Michael | 3800   |
| 7           | Addilyn | 7400   |
| 8           | Juan    | 6100   |
| 9           | Kannon  | 7700   |
+-------------+---------+--------+
Output: 
+-------------+-------+
| employee_id | bonus |
+-------------+-------+
| 2           | 0     |
| 3           | 0     |
| 7           | 7400  |
| 8           | 0     |
| 9           | 7700  |
+-------------+-------+
Explanation: 
The employees with IDs 2 and 8 get 0 bonus because they have an even employee_id.
The employee with ID 3 gets 0 bonus because their name starts with 'M'.
The rest of the employees get a 100% bonus.
</pre>


```sql
/*
According to the Problem we need employee_id and bonus as output but, we aren't having any bonus column. 
In this scenario we will use CASE to create bonus for the output table using conditions given in the problem 
where "M%" is a wildcard stating anything starting with M. If conditions are matched it is same as salary ie 100% else it is 0

<> is not equal to in sql

METACHARACTER	DESCRIPTION	EXAMPLE	EXAMPLES MATCHES
^	    Start the match at the beginning of a string	        ^c%	cat, car, chain
|	    Alternation (either of two alternatives)	            c(a|o)%	can, corn, cop
()	    Group items in a single logical item	                c(a|o)%	can, corn, cop
_	    Any single character (using LIKE and SIMILAR TO)	    c_	co, fico, pico
%	    Any string (using LIKE and SIMILAR TO)	                c%	chart, articulation, crate
.	    Any single character (using POSIX)	                    c.	co, fico, pico
.*	    Any string (using POSIX)	                            c.*	chart, articulation, crate
+	    Repetition of the previous item one or more times	    co+	coo, cool

There are three ways to use regex comparisons in SQL:

LIKE
SIMILAR TO
POSIX comparators
LIKE and SIMILAR TO are used for basic comparisons where you are looking for a matching string. LIKE and SIMILAR TO 
both look and compare string patterns, the only difference is that SIMILAR TO uses the SQL99 definition for regular 
expressions and LIKE uses PSQL’s definition for regular expressions.

Syntax: [String or Column name] LIKE/SIMILAR TO [Regex]

EXPRESSION	RETURNS
‘char’ LIKE ‘char’	                True
‘char’ LIKE ‘c%’	                True
‘char’ LIKE ‘ha’	                True
‘char’ LIKE ‘c’	                    False
‘char’ SIMILAR TO ‘char’	        True
‘char’ SIMILAR TO ‘%(h|g)%’	        True
‘char’ SIMILAR TO ‘h’	            False
‘char’ SIMILAR TO ‘(a|b)%’	        False


*/
# Syntax for IF clause :

# SELECT column1, column2
# IF(condition, Result if condition is true, Result if condition is false) AS alias_name
# FROM table_name

# SOLUTION USING IF CLAUSE: 
SELECT employee_id,
If(employee_id%2 != 0 AND name NOT LIKE 'M%', salary, 0) AS bonus
FROM Employees
ORDER BY employee_id;


# Syntax for CASE clause :
# SELECT column1, column2,
# CASE
# WHEN condition1 THEN result1
# WHEN condition2 THEN result2
# WHEN condition3 THEN result3
# ELSE result
# END AS alias_name
# FROM table_name

# SOLUTION USING CASE CLAUSE:
SELECT employee_id,
CASE
WHEN employee_id % 2 != 0 AND name NOT LIKE 'M%' THEN salary
ELSE 0
END AS bonus
FROM Employees
ORDER BY employee_id


# using union 
select employee_id,salary as bonus from Employees where mod(employee_id,2) =1 and name not like 'M%' 
union 
select employee_id, 0 as bonus from Employees where mod(employee_id,2) =0 or name like 'M%'
order by employee_id
```







<br /> <br /> <br /> **[627. Swap Salary](https://leetcode.com/problems/swap-salary/)**<br />
Table: `Salary`<br />
<pre>
+-------------+----------+
| Column Name | Type     |
+-------------+----------+
| id          | int      |
| name        | varchar  |
| sex         | ENUM     |
| salary      | int      |
+-------------+----------+
id is the primary key for this table.
The sex column is ENUM value of type ('m', 'f').
The table contains information about an employee.
</pre>
Write an SQL query to swap all `'f'` and `'m'` values (i.e., change all `'f'` values to `'m'` and vice versa) with a **single update statement** and no intermediate temporary tables.<br />
Note that you must write a single update statement, **do not** write any select statement for this problem.<br />
The query result format is in the following example.<br />
>Example 1:<br />
<pre>
Input: 
Salary table:
+----+------+-----+--------+
| id | name | sex | salary |
+----+------+-----+--------+
| 1  | A    | m   | 2500   |
| 2  | B    | f   | 1500   |
| 3  | C    | m   | 5500   |
| 4  | D    | f   | 500    |
+----+------+-----+--------+
Output: 
+----+------+-----+--------+
| id | name | sex | salary |
+----+------+-----+--------+
| 1  | A    | f   | 2500   |
| 2  | B    | m   | 1500   |
| 3  | C    | f   | 5500   |
| 4  | D    | m   | 500    |
+----+------+-----+--------+
Explanation: 
(1, A) and (3, C) were changed from 'm' to 'f'.
(2, B) and (4, D) were changed from 'f' to 'm'.
</pre>

```sql
-- using if/else 
UPDATE SALARY 
SET 
	SEX = CASE 
			WHEN SEX = 'f' THEN 'm'
			ELSE 'f'
		  END;
       
-- This is the syntax for "IF" => IF(condition, value_if_true, value_if_false).
UPDATE Salary 
    SET sex = if(sex ='m','f','m');
    
-- Using then
UPDATE Salary SET sex = (
  CASE sex
  WHEN 'm' THEN 'f'
  WHEN 'f' THEN 'm'
  END
)
```









<br /> <br /> <br /> **[196. Delete Duplicate Emails](https://leetcode.com/problems/delete-duplicate-emails/)**<br />
Table: `Person`<br />
<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| email       | varchar |
+-------------+---------+
id is the primary key column for this table.
Each row of this table contains an email. The emails will not contain uppercase letters.
</pre>
Write an SQL query to **delete** all the duplicate emails, keeping only one unique email with the smallest `id`. Note that you are supposed to write a `DELETE` statement and not a `SELECT` one.<br />
After running your script, the answer shown is the `Person` table. The driver will first compile and run your piece of code and then show the `Person` table. The final order of the `Person` table **does not matter**.<br />
The query result format is in the following example.<br />
>Example 1:<br />
<pre>
Input: 
Person table:
+----+------------------+
| id | email            |
+----+------------------+
| 1  | john@example.com |
| 2  | bob@example.com  |
| 3  | john@example.com |
+----+------------------+
Output: 
+----+------------------+
| id | email            |
+----+------------------+
| 1  | john@example.com |
| 2  | bob@example.com  |
+----+------------------+
Explanation: john@example.com is repeated two times. We keep the row with the smallest Id = 1.
</pre>

```sql
-- using delete operator 
DELETE p1 FROM Person as p1, Person as p2 WHERE p1.Email = p2.Email AND p1.Id > p2.Id;

-- using min operator 
with t as (select min(id) as min_id from person group by email) delete from person where id not in (select min_id from t);

-- using order by, join
DELETE FROM Person WHERE id IN(
SELECT
t.id
FROM
(
SELECT e1.id
FROM Person e1
JOIN Person e2 ON(e1.email = e2.email)
WHERE e1.id <> e2.id AND e1.id > e2.id
ORDER BY e1.id DESC
)AS t
)

-- using group by 
DELETE FROM Person
WHERE Id NOT IN(
    SELECT * 
    FROM(
        SELECT MIN(Id)
        FROM Person
        GROUP BY Email
    )
    as p
)

-- using partition by  
/*
We use SQL PARTITION BY to divide the result set into partitions and perform computation on each subset of partitioned data
*/
WITH myCTE AS(
SELECT *, ROW_NUMBER() OVER(PARTITION BY email ORDER BY id ASC) DuplicateCount
FROM Person) 
DELETE FROM myCTE WHERE DuplicateCount > 1

/*
we do a self-join when we need to compare the value within a table vertically, as when we do the self-join the table with itself, each row can be compared with all rows.
*/

-- using join 
DELETE tb1
FROM Person tb1
JOIN Person tb2 ON tb1.email = tb2.email
WHERE tb1.id > tb2.id

-- using not 
delete from Person where Id not in(select MIN(Id) from Person group by email)
```








<br /> <br /> <br /> **[1667. Fix Names in a Table](https://leetcode.com/problems/fix-names-in-a-table/)**<br />
Table: `Users`<br />
<pre>
+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| user_id        | int     |
| name           | varchar |
+----------------+---------+
user_id is the primary key for this table.
This table contains the ID and the name of the user. The name consists of only lowercase and uppercase characters.
</pre>
Write an SQL query to fix the names so that only the first character is uppercase and the rest are lowercase.<br />
Return the result table ordered by `user_id`.<br />
The query result format is in the following example.<br />

>Example 1:<br />
<pre>
Input: 
Users table:
+---------+-------+
| user_id | name  |
+---------+-------+
| 1       | aLice |
| 2       | bOB   |
+---------+-------+
Output: 
+---------+-------+
| user_id | name  |
+---------+-------+
| 1       | Alice |
| 2       | Bob   |
+---------+-------+
</pre>

```sql
# SUBSTR(string_name , start_index ,end_index)
SELECT user_id,CONCAT(UPPER(SUBSTR(name,1,1)),LOWER(SUBSTR(name,2,length(name)))) AS name
FROM Users ORDER BY user_id;

# second method 
SELECT user_id, concat(upper(LEFT(name, 1)), lower(RIGHT(name, length(name)-1))) as name
FROM users
ORDER BY user_id;

# INITCAP returns char , with the first letter of each word in uppercase, all other letters in lowercase. 
# Words are delimited by white space or characters that are not alphanumeric. char can be of any of the
# datatypes CHAR , VARCHAR2 , NCHAR , or NVARCHAR2 . The return value is the same datatype as char .
SELECT user_id, INITCAP(name) AS name FROM Users
    ORDER BY user_id;
```










<br /> <br /> <br /> **[1484. Group Sold Products By The Date](https://leetcode.com/problems/group-sold-products-by-the-date/)**<br />
Table `Activities`:<br />
<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| sell_date   | date    |
| product     | varchar |
+-------------+---------+
There is no primary key for this table, it may contain duplicates.
Each row of this table contains the product name and the date it was sold in a market.
</pre>
Write an SQL query to find for each date the number of different products sold and their names.<br />
The sold products names for each date should be sorted lexicographically.<br />
Return the result table ordered by `sell_date`.<br />
The query result format is in the following example.<br />

>Example 1:<br />
<pre>
Input: 
Activities table:
+------------+------------+
| sell_date  | product     |
+------------+------------+
| 2020-05-30 | Headphone  |
| 2020-06-01 | Pencil     |
| 2020-06-02 | Mask       |
| 2020-05-30 | Basketball |
| 2020-06-01 | Bible      |
| 2020-06-02 | Mask       |
| 2020-05-30 | T-Shirt    |
+------------+------------+
Output: 
+------------+----------+------------------------------+
| sell_date  | num_sold | products                     |
+------------+----------+------------------------------+
| 2020-05-30 | 3        | Basketball,Headphone,T-shirt |
| 2020-06-01 | 2        | Bible,Pencil                 |
| 2020-06-02 | 1        | Mask                         |
+------------+----------+------------------------------+
Explanation: 
For 2020-05-30, Sold items were (Headphone, Basketball, T-shirt), we sort them lexicographically and separate them by a comma.
For 2020-06-01, Sold items were (Pencil, Bible), we sort them lexicographically and separate them by a comma.
For 2020-06-02, the Sold item is (Mask), we just return it.
</pre>

```sql
# GROUP CONCAT is the function in mySQL which returns the row values in the comma separated fashion.
SELECT sell_date, COUNT(DISTINCT product) as 'num_sold',
    GROUP_CONCAT(DISTINCT product ORDER BY product) AS 'products'
    FROM Activities
    GROUP BY sell_date
    ORDER BY sell_date
    
SELECT TO_CHAR(sell_date, 'YYYY-MM-DD') AS "sell_date", 
    COUNT(DISTINCT(product)) AS "num_sold",
    LISTAGG(DISTINCT(product), ',') WITHIN GROUP (ORDER BY product) AS "products"
    FROM activities 
    GROUP BY sell_date 
    ORDER BY sell_date;
    
SELECT TO_CHAR(sell_date, 'YYYY-MM-DD') AS "sell_date", 
    COUNT(DISTINCT(product)) AS "num_sold",
    LISTAGG(product, ',') WITHIN GROUP (ORDER BY product) AS "products"
    FROM (
        SELECT DISTINCT product, sell_date 
        FROM activities
    ) 
    GROUP BY sell_date 
    ORDER BY sell_date;
```










<br /> <br /> <br /> **[1527. Patients With a Condition](https://leetcode.com/problems/patients-with-a-condition/)**<br />
Table: `Patients`<br />
<pre>
+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| patient_id   | int     |
| patient_name | varchar |
| conditions   | varchar |
+--------------+---------+
patient_id is the primary key for this table.
'conditions' contains 0 or more code separated by spaces. 
This table contains information of the patients in the hospital.
</pre>
Write an SQL query to report the patient_id, patient_name all conditions of patients who have Type I Diabetes. Type I Diabetes always starts with `DIAB1` prefix<br />
Return the result table in **any order**.<br />
The query result format is in the following example.<br />

>Example 1:<br />
<pre>
Input: 
Patients table:
+------------+--------------+--------------+
| patient_id | patient_name | conditions   |
+------------+--------------+--------------+
| 1          | Daniel       | YFEV COUGH   |
| 2          | Alice        |              |
| 3          | Bob          | DIAB100 MYOP |
| 4          | George       | ACNE DIAB100 |
| 5          | Alain        | DIAB201      |
+------------+--------------+--------------+
Output: 
+------------+--------------+--------------+
| patient_id | patient_name | conditions   |
+------------+--------------+--------------+
| 3          | Bob          | DIAB100 MYOP |
| 4          | George       | ACNE DIAB100 | 
+------------+--------------+--------------+
Explanation: Bob and George both have a condition that starts with DIAB1.
</pre>

```sql
select patient_id, patient_name,conditions
from Patients
where conditions like 'DIAB1%' or conditions like '% DIAB1%';
```









<br /> <br /> <br /> **[1965. Employees With Missing Information](https://leetcode.com/problems/employees-with-missing-information/)**<br />
Table: `Employees`<br />
<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| employee_id | int     |
| name        | varchar |
+-------------+---------+
employee_id is the primary key for this table.
Each row of this table indicates the name of the employee whose ID is employee_id.
</pre>
Table: `Salaries`<br />
<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| employee_id | int     |
| salary      | int     |
+-------------+---------+
employee_id is the primary key for this table.
Each row of this table indicates the salary of the employee whose ID is employee_id.
</pre>
Write an SQL query to report the IDs of all the employees with **missing information**. The information of an employee is missing if:<br />

 * The employee's `name` is missing, or<br />
 * The employee's `salary` is missing.<br />

Return the result table ordered by `employee_id` **in ascending order**.<br />
The query result format is in the following example.<br />

>Example 1:<br />
<pre>
Input: 
Employees table:
+-------------+----------+
| employee_id | name     |
+-------------+----------+
| 2           | Crew     |
| 4           | Haven    |
| 5           | Kristian |
+-------------+----------+
Salaries table:
+-------------+--------+
| employee_id | salary |
+-------------+--------+
| 5           | 76071  |
| 1           | 22517  |
| 4           | 63539  |
+-------------+--------+
Output: 
+-------------+
| employee_id |
+-------------+
| 1           |
| 2           |
+-------------+
Explanation: 
Employees 1, 2, 4, and 5 are working at this company.
The name of employee 1 is missing.
The salary of employee 2 is missing.
</pre>

```sql
WITH CTE (employee_id)
AS 
(
SELECT employee_id
FROM Salaries
WHERE employee_id not in (SELECT employee_id FROM Employees)
UNION
SELECT employee_id
FROM Employees
WHERE employee_id not in (SELECT employee_id FROM Salaries))
SELECT employee_id from CTE
ORDER BY employee_id;

# The SQL server's Coalesce function is used to handle the Null values. 
# The null values are replaced with user-defined values during the expression evaluation process. 
# This function evaluates arguments in a particular order from the provided arguments list 
# and always returns the first non-null value.

SELECT COALESCE(e.employee_id, s.employee_id) AS employee_id
FROM Employees e FULL JOIN Salaries s
ON e.employee_id = s.employee_id
WHERE e.employee_id IS NULL OR s.employee_id IS NULL
ORDER BY employee_id;

select employee_id from Employees where employee_id not in (select employee_id from Salaries)
union
select employee_id from Salaries where employee_id not in (select employee_id from Employees) order by employee_id;

SELECT e.employee_id
FROM Employees e
LEFT JOIN Salaries s ON e.employee_id = s.employee_id
WHERE s.employee_id IS NULL
UNION
SELECT s.employee_id
FROM Employees e
RIGHT JOIN Salaries s ON e.employee_id = s.employee_id
WHERE e.employee_id IS NULL
ORDER BY employee_id
```









<br /> <br /> <br /> **[1795. Rearrange Products Table](https://leetcode.com/problems/rearrange-products-table/)**<br />
Table: `Products`<br />
<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| product_id  | int     |
| store1      | int     |
| store2      | int     |
| store3      | int     |
+-------------+---------+
product_id is the primary key for this table.
Each row in this table indicates the product's price in 3 different stores: store1, store2, and store3.
If the product is not available in a store, the price will be null in that store's column.
</pre>
Write an SQL query to rearrange the `Products` table so that each row has `(product_id, store, price)`. If a product is not available in a store, do **not** include a row with that `product_id` and `store` combination in the result table.<br />
Return the result table in **any order**.<br />
The query result format is in the following example.<br />

>Example 1:<br />
<pre>
Input: 
Products table:
+------------+--------+--------+--------+
| product_id | store1 | store2 | store3 |
+------------+--------+--------+--------+
| 0          | 95     | 100    | 105    |
| 1          | 70     | null   | 80     |
+------------+--------+--------+--------+
Output: 
+------------+--------+-------+
| product_id | store  | price |
+------------+--------+-------+
| 0          | store1 | 95    |
| 0          | store2 | 100   |
| 0          | store3 | 105   |
| 1          | store1 | 70    |
| 1          | store3 | 80    |
+------------+--------+-------+
Explanation: 
Product 0 is available in all three stores with prices 95, 100, and 105 respectively.
Product 1 is available in store1 with price 70 and store3 with price 80. The product is not available in store2.
</pre>

```sql
select product_id,'store1' as store, store1 as price from products where store1 is not null
union
select product_id,'store2' as store, store2 as price from products where store2 is not null
union
select product_id,'store3' as store, store3 as price from products where store3 is not null
order by product_id
```










<br /> <br /> <br /> **[608. Tree Node](https://leetcode.com/problems/tree-node/)**<br />
Table: `Tree`<br />
<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| id          | int  |
| p_id        | int  |
+-------------+------+
id is the primary key column for this table.
Each row of this table contains information about the id of a node and the id of its parent node in a tree.
The given structure is always a valid tree.
</pre>
Each node in the tree can be one of three types:<br />

 * "Leaf": if the node is a leaf node.<br />
 * "Root": if the node is the root of the tree.<br />
 * "Inner": If the node is neither a leaf node nor a root node.<br />

Write an SQL query to report the type of each node in the tree.<br />
Return the result table **ordered** by `id` **in ascending order**.<br />
The query result format is in the following example.<br />

>Example 1:<br />
<img src = "https://assets.leetcode.com/uploads/2021/10/22/tree1.jpg"><br />
<pre>
Input: 
Tree table:
+----+------+
| id | p_id |
+----+------+
| 1  | null |
| 2  | 1    |
| 3  | 1    |
| 4  | 2    |
| 5  | 2    |
+----+------+
Output: 
+----+-------+
| id | type  |
+----+-------+
| 1  | Root  |
| 2  | Inner |
| 3  | Leaf  |
| 4  | Leaf  |
| 5  | Leaf  |
+----+-------+
Explanation: 
Node 1 is the root node because its parent node is null and it has child nodes 2 and 3.
Node 2 is an inner node because it has parent node 1 and child node 4 and 5.
Nodes 3, 4, and 5 are leaf nodes because they have parent nodes and they do not have child nodes.
</pre>
>Example 2:<br />
<img src = "https://assets.leetcode.com/uploads/2021/10/22/tree2.jpg"><br />
<pre>
Input: 
Tree table:
+----+------+
| id | p_id |
+----+------+
| 1  | null |
+----+------+
Output: 
+----+-------+
| id | type  |
+----+-------+
| 1  | Root  |
+----+-------+
Explanation: If there is only one node on the tree, you only need to output its root attributes.
</pre>

```sql
select id,
case when p_id is null then "Root"
when id in (select p_id from tree) then "Inner"
else "Leaf" end as type
from tree


SELECT
    id,
    CASE
        WHEN p_id IS NULL THEN 'Root'
        WHEN id IN 
            (SELECT
                p_id 
             FROM Tree 
             WHERE NOT p_id IS NULL) THEN 'Inner'
    ELSE 'Leaf'
    END AS type
FROM Tree


select id, 
case 
    when p_id is null then 'Root'
    when id in (select p_id from Tree) then 'Inner'
    else 'Leaf'
end 
as type 
from Tree


SELECT id, CASE 
WHEN p_id IS NULL THEN 'Root'
WHEN id IN (SELECT p_id FROM Tree) THEN 'Inner'
ELSE 'Leaf' END type
FROM Tree


SELECT id, (CASE
    WHEN t.p_id IS NULL THEN 'Root'
    WHEN t.id IN (SELECT p_id FROM Tree) THEN 'Inner'
    ELSE 'Leaf'
    END
) AS type FROM Tree t 
    ORDER BY t.id


select id, if(p_id is null, 'Root', if(id in (select p_id from Tree), 'Inner', 'Leaf'))as type from Tree order by id


select tree.id,case when tree.p_id is Null then 'Root'
when cnt>=1 then 'Inner'
else 'Leaf' end as type
from tree left join (
select k.p_id as p,count(*) as cnt from tree t join tree k on t.id=k.p_id group by k.p_id
)o
on o.p=tree.id
```













<br /> <br /> <br /> **[176. Second Highest Salary](https://leetcode.com/problems/second-highest-salary/)**<br />
Table: `Employee`<br />
<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| id          | int  |
| salary      | int  |
+-------------+------+
id is the primary key column for this table.
Each row of this table contains information about the salary of an employee.
</pre>
Write an SQL query to report the second highest salary from the `Employee` table. If there is no second highest salary, the query should report `null`.<br />
The query result format is in the following example.<br />
>Example 1:<br />
<pre>
Input: 
Employee table:
+----+--------+
| id | salary |
+----+--------+
| 1  | 100    |
| 2  | 200    |
| 3  | 300    |
+----+--------+
Output: 
+---------------------+
| SecondHighestSalary |
+---------------------+
| 200                 |
+---------------------+
</pre>
>Example 2:<br />
<pre>
Input: 
Employee table:
+----+--------+
| id | salary |
+----+--------+
| 1  | 100    |
+----+--------+
Output: 
+---------------------+
| SecondHighestSalary |
+---------------------+
| null                |
+---------------------+
</pre>

```sql
SELECT MAX(Salary) AS SecondHighestSalary 
FROM Employee 
WHERE Salary NOT IN 
(
    SELECT MAX(Salary) 
    FROM Employee
)


SELECT MAX(salary) as SecondHighestSalary
FROM 
( 
    SELECT salary FROM Employee
    WHERE salary < (select max(salary) from employee)
) as Emp


# if the table has only 1 record, and you select where rank=2 which will give an error
SELECT MAX(salary) AS SecondHighestSalary
FROM (SELECT salary, dense_rank() over(ORDER BY salary DESC) AS rnk
     FROM Employee) ranks
WHERE rnk = 2


Select(Select distinct salary from employee 
order by salary desc
limit 1,1) as 'SecondHighestSalary' ;


with tempTable as (select dense_rank() over(order by salary desc) rownum,salary from Employee)
select max(tb.SecondHighestSalary) as SecondHighestSalary from (select salary as SecondHighestSalary 
            from tempTable where rownum=2
union

select null from tempTable group by salary having count(distinct salary)=1) tb


-- Used Distinct to handle the case if there are more than 1 employee with same salary.
-- Used dense_ranke() to get the right sorting in case the hightest salary repeatedf
-- Used Max_RN to get the highest salary
-- Used CNT to get the count of the records
SELECT DISTINCT CASE WHEN (RN = 2) THEN SALARY
ELSE NULL
END AS SecondHighestSalary
FROM(
SELECT SALARY,CNT,RN,MAX(RN) OVER() AS MAX_RN
FROM(
SELECT SALARY,DENSE_RANK() OVER(ORDER BY SALARY DESC) RN,COUNT(1) OVER() CNT
FROM Employee
) DETAILS
)FINAL
WHERE FINAL.CNT = 1 OR (FINAL.CNT > 1 AND (FINAL.RN = 2 OR MAX_RN = 1))


SELECT
    IF
        (MAX(salary) != MIN(salary),
        (SELECT DISTINCT salary
        FROM Employee
        ORDER BY salary DESC LIMIT 1 OFFSET 1),
        NULL)
    AS SecondHighestSalary
FROM Employee;


# CTE was introduced in SQL Server 2005, the common table expression (CTE) is a temporary named result
# set that you can reference within a SELECT, INSERT, UPDATE, or DELETE statement. 
# You can also use a CTE in a CREATE a view, as part of the view's SELECT query.
with cte as
(
select
salary,
dense_rank()over(order by salary desc) as rnk
from employee
)
select
case when (select distinct salary from cte where rnk=2) is null then null
else (select distinct salary from cte where rnk=2)
end as SecondHighestSalary
```








<br /> <br /> <br /> **[175. Combine Two Tables](https://leetcode.com/problems/combine-two-tables/)**<br />
Table: `Person`<br />
<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| personId    | int     |
| lastName    | varchar |
| firstName   | varchar |
+-------------+---------+
personId is the primary key column for this table.
This table contains information about the ID of some persons and their first and last names.
</pre>
Table: `Address`<br />
<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| addressId   | int     |
| personId    | int     |
| city        | varchar |
| state       | varchar |
+-------------+---------+
addressId is the primary key column for this table.
Each row of this table contains information about the city and state of one person with ID = PersonId.
</pre>
Write an SQL query to report the first name, last name, city, and state of each person in the `Person` table. If the address of a `personId` is not present in the `Address` table, report `null` instead.<br />
Return the result table in **any order**.<br />
The query result format is in the following example.<br />

>Example 1:<br />
<pre>
Input: 
Person table:
+----------+----------+-----------+
| personId | lastName | firstName |
+----------+----------+-----------+
| 1        | Wang     | Allen     |
| 2        | Alice    | Bob       |
+----------+----------+-----------+
Address table:
+-----------+----------+---------------+------------+
| addressId | personId | city          | state      |
+-----------+----------+---------------+------------+
| 1         | 2        | New York City | New York   |
| 2         | 3        | Leetcode      | California |
+-----------+----------+---------------+------------+
Output: 
+-----------+----------+---------------+----------+
| firstName | lastName | city          | state    |
+-----------+----------+---------------+----------+
| Allen     | Wang     | Null          | Null     |
| Bob       | Alice    | New York City | New York |
+-----------+----------+---------------+----------+
Explanation: 
There is no address in the address table for the personId = 1 so we return null in their city and state.
addressId = 1 contains information about the address of personId = 2.
</pre>

```sql
SELECT FirstName, LastName, City, State FROM Person LEFT JOIN Address ON Person.PersonId = Address.PersonId;


select p1.firstName, p1.lastName, a1.city, a1.state from person as p1
left join address as a1 on p1.personId = a1.personId


P.lastName as lastName,
nvl(A.city,null) as city,
nvl(A.state,null) as state
from Person P left join Address A
on P.personId = A.personId  


select ps.firstname, ps.lastname, (select city from address where ps.personid = address.personid) as city, (select state from address where ps.personid = address.personid) as state from person as ps


select p.firstname,p.lastname,c.city,c.state
from person p, address c
where p.personid=c.personid
union
select p.firstname,p.lastname,null as city,null as state
from person as p
where p.personid not in (select personid from address);


SELECT 
    p.firstName, 
    p.lastName, 
    a.city, 
    a.state 
FROM 
    Person AS p 
LEFT JOIN 
    Address AS a 
ON 
    p.personId=a.personId;
```











<br /> <br /> <br /> **[1581. Customer Who Visited but Did Not Make Any Transactions](https://leetcode.com/problems/customer-who-visited-but-did-not-make-any-transactions/)**<br />
Table: `Visits`<br />
<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| visit_id    | int     |
| customer_id | int     |
+-------------+---------+
visit_id is the primary key for this table.
This table contains information about the customers who visited the mall.
</pre>
Table: `Transactions`<br />
<pre>
+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| transaction_id | int     |
| visit_id       | int     |
| amount         | int     |
+----------------+---------+
transaction_id is the primary key for this table.
This table contains information about the transactions made during the visit_id.
</pre>
Write an SQL query to find the IDs of the users who visited without making any transactions and the number of times they made these types of visits.<br />
Return the result table sorted in **any order**.<br />
The query result format is in the following example.<br />

>Example 1:<br />
<pre>
Input: 
Visits
+----------+-------------+
| visit_id | customer_id |
+----------+-------------+
| 1        | 23          |
| 2        | 9           |
| 4        | 30          |
| 5        | 54          |
| 6        | 96          |
| 7        | 54          |
| 8        | 54          |
+----------+-------------+
Transactions
+----------------+----------+--------+
| transaction_id | visit_id | amount |
+----------------+----------+--------+
| 2              | 5        | 310    |
| 3              | 5        | 300    |
| 9              | 5        | 200    |
| 12             | 1        | 910    |
| 13             | 2        | 970    |
+----------------+----------+--------+
Output: 
+-------------+----------------+
| customer_id | count_no_trans |
+-------------+----------------+
| 54          | 2              |
| 30          | 1              |
| 96          | 1              |
+-------------+----------------+
Explanation: 
Customer with id = 23 visited the mall once and made one transaction during the visit with id = 12.
Customer with id = 9 visited the mall once and made one transaction during the visit with id = 13.
Customer with id = 30 visited the mall once and did not make any transactions.
Customer with id = 54 visited the mall three times. During 2 visits they did not make any transactions, and during one visit they made 3 transactions.
Customer with id = 96 visited the mall once and did not make any transactions.
As we can see, users with IDs 30 and 96 visited the mall one time without making any transactions. Also, user 54 visited the mall twice and did not make any transactions.
</pre>

```sql
SELECT customer_id, COUNT(customer_id) AS count_no_trans
FROM Visits
LEFT JOIN Transactions ON
Transactions.visit_id = Visits.visit_id
WHERE transaction_id IS NULL
GROUP BY customer_id


select customer_id, count(customer_id) as count_no_trans from visits 
where visit_id not in (select visit_id from Transactions) group by customer_id;


select customer_id, count(customer_id) as count_no_trans
from visits as v left join Transactions as t  on v.visit_id = t.visit_id
where transaction_id is null group by customer_id;


select customer_id, count(customer_id) as count_no_trans
from Visits where visit_id in 
    (select visit_id from Visits where visit_id not in 
     (select distinct visit_id from Transactions)
    ) 
group by customer_id


SELECT customer_id, COUNT(visit_id) AS count_no_trans
FROM Visits
WHERE visit_id NOT IN (SELECT visit_id FROM Transactions)
GROUP BY customer_id;
```










<br /> <br /> <br /> **[1148. Article Views I](https://leetcode.com/problems/article-views-i/)**<br />
Table: `Views`<br />
<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| article_id    | int     |
| author_id     | int     |
| viewer_id     | int     |
| view_date     | date    |
+---------------+---------+
There is no primary key for this table, it may have duplicate rows.
Each row of this table indicates that some viewer viewed an article (written by some author) on some date. 
Note that equal author_id and viewer_id indicate the same person.
</pre>
Write an SQL query to find all the authors that viewed at least one of their own articles.
Return the result table sorted by `id` in ascending order.
The query result format is in the following example.

>Example 1:<br />
<pre>
Input: 
Views table:
+------------+-----------+-----------+------------+
| article_id | author_id | viewer_id | view_date  |
+------------+-----------+-----------+------------+
| 1          | 3         | 5         | 2019-08-01 |
| 1          | 3         | 6         | 2019-08-02 |
| 2          | 7         | 7         | 2019-08-01 |
| 2          | 7         | 6         | 2019-08-02 |
| 4          | 7         | 1         | 2019-07-22 |
| 3          | 4         | 4         | 2019-07-21 |
| 3          | 4         | 4         | 2019-07-21 |
+------------+-----------+-----------+------------+
Output: 
+------+
| id   |
+------+
| 4    |
| 7    |
+------+
</pre>

```sql
select author_id as id from views 
where author_id = viewer_id 
group by author_id 
order by author_id;


select distinct author_id as id from Views where author_id = viewer_id order by author_id
```







<br /> <br /> <br /> **[197. Rising Temperature](https://leetcode.com/problems/rising-temperature/)**<br />
Table: `Weather`<br />
<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| recordDate    | date    |
| temperature   | int     |
+---------------+---------+
id is the primary key for this table.
This table contains information about the temperature on a certain day.
</pre>
Write an SQL query to find all dates' `Id` with higher temperatures compared to its previous dates (yesterday).<br />
Return the result table in **any order**.<br />
The query result format is in the following example.<br />

>Example 1:<br />
<pre>
Input: 
Weather table:
+----+------------+-------------+
| id | recordDate | temperature |
+----+------------+-------------+
| 1  | 2015-01-01 | 10          |
| 2  | 2015-01-02 | 25          |
| 3  | 2015-01-03 | 20          |
| 4  | 2015-01-04 | 30          |
+----+------------+-------------+
Output: 
+----+
| id |
+----+
| 2  |
| 4  |
+----+
Explanation: 
In 2015-01-02, the temperature was higher than the previous day (10 -> 25).
In 2015-01-04, the temperature was higher than the previous day (20 -> 30).
</pre>

```sql
-- Using ADDDATE : -
select w2.id from weather w1 
inner join weather w2 where w2.recordDate = ADDDATE(w1.recordDate, 1)
and w1.temperature < w2.temperature;


-- Using SUBDATE : -
select w2.id from weather w1 
inner join weather w2 where w1.recordDate = SUBDATE(w2.recordDate, 1)
and w1.temperature < w2.temperature;


-- Using DATEDIFF : -
select w2.id from weather w1 
inner join weather w2 where DATEDIFF(w2.recordDate, w1.recordDate)
and w1.temperature < w2.temperature;
```











<br /> <br /> <br /> **[607. Sales Person](https://leetcode.com/problems/sales-person/)**<br />
Table: `SalesPerson`<br />
<pre>
+-----------------+---------+
| Column Name     | Type    |
+-----------------+---------+
| sales_id        | int     |
| name            | varchar |
| salary          | int     |
| commission_rate | int     |
| hire_date       | date    |
+-----------------+---------+
sales_id is the primary key column for this table.
Each row of this table indicates the name and the ID of a salesperson alongside their salary, commission rate, and hire date.
</pre>
Table: `Company`<br />
<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| com_id      | int     |
| name        | varchar |
| city        | varchar |
+-------------+---------+
com_id is the primary key column for this table.
Each row of this table indicates the name and the ID of a company and the city in which the company is located.
</pre>
Table: `Orders`<br />
<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| order_id    | int  |
| order_date  | date |
| com_id      | int  |
| sales_id    | int  |
| amount      | int  |
+-------------+------+
order_id is the primary key column for this table.
com_id is a foreign key to com_id from the Company table.
sales_id is a foreign key to sales_id from the SalesPerson table.
Each row of this table contains information about one order. This includes the ID of the company, the ID of the salesperson, the date of the order, and the amount paid.
</pre>
Write an SQL query to report the names of all the salespersons who did not have any orders related to the company with the name **"RED"**.<br />
Return the result table in **any order**.<br />
The query result format is in the following example.<br />

>Example 1:<br />
<pre>
Input: 
SalesPerson table:
+----------+------+--------+-----------------+------------+
| sales_id | name | salary | commission_rate | hire_date  |
+----------+------+--------+-----------------+------------+
| 1        | John | 100000 | 6               | 4/1/2006   |
| 2        | Amy  | 12000  | 5               | 5/1/2010   |
| 3        | Mark | 65000  | 12              | 12/25/2008 |
| 4        | Pam  | 25000  | 25              | 1/1/2005   |
| 5        | Alex | 5000   | 10              | 2/3/2007   |
+----------+------+--------+-----------------+------------+
Company table:
+--------+--------+----------+
| com_id | name   | city     |
+--------+--------+----------+
| 1      | RED    | Boston   |
| 2      | ORANGE | New York |
| 3      | YELLOW | Boston   |
| 4      | GREEN  | Austin   |
+--------+--------+----------+
Orders table:
+----------+------------+--------+----------+--------+
| order_id | order_date | com_id | sales_id | amount |
+----------+------------+--------+----------+--------+
| 1        | 1/1/2014   | 3      | 4        | 10000  |
| 2        | 2/1/2014   | 4      | 5        | 5000   |
| 3        | 3/1/2014   | 1      | 1        | 50000  |
| 4        | 4/1/2014   | 1      | 4        | 25000  |
+----------+------------+--------+----------+--------+
Output: 
+------+
| name |
+------+
| Amy  |
| Mark |
| Alex |
+------+
Explanation: 
According to orders 3 and 4 in the Orders table, it is easy to tell that only salesperson John and Pam have sales to company RED, so we report all the other names in the table salesperson.
</pre>

```sql
SELECT name 
FROM SalesPerson
WHERE sales_id NOT IN (SELECT sales_id FROM Orders WHERE com_id = (SELECT com_id FROM Company WHERE NAME = 'RED'))
```











<br /> <br /> <br /> **[1141. User Activity for the Past 30 Days I](https://leetcode.com/problems/user-activity-for-the-past-30-days-i/)**<br />
Table: `Activity`<br />
<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| user_id       | int     |
| session_id    | int     |
| activity_date | date    |
| activity_type | enum    |
+---------------+---------+
There is no primary key for this table, it may have duplicate rows.
The activity_type column is an ENUM of type ('open_session', 'end_session', 'scroll_down', 'send_message').
The table shows the user activities for a social media website. 
Note that each session belongs to exactly one user.
</pre>
Write an SQL query to find the daily active user count for a period of `30` days ending `2019-07-27` inclusively. A user was active on someday if they made at least one activity on that day.<br />
Return the result table in **any order**.<br />
The query result format is in the following example.<br />

>Example 1:<br />
<pre>
Input: 
Activity table:
+---------+------------+---------------+---------------+
| user_id | session_id | activity_date | activity_type |
+---------+------------+---------------+---------------+
| 1       | 1          | 2019-07-20    | open_session  |
| 1       | 1          | 2019-07-20    | scroll_down   |
| 1       | 1          | 2019-07-20    | end_session   |
| 2       | 4          | 2019-07-20    | open_session  |
| 2       | 4          | 2019-07-21    | send_message  |
| 2       | 4          | 2019-07-21    | end_session   |
| 3       | 2          | 2019-07-21    | open_session  |
| 3       | 2          | 2019-07-21    | send_message  |
| 3       | 2          | 2019-07-21    | end_session   |
| 4       | 3          | 2019-06-25    | open_session  |
| 4       | 3          | 2019-06-25    | end_session   |
+---------+------------+---------------+---------------+
Output: 
+------------+--------------+ 
| day        | active_users |
+------------+--------------+ 
| 2019-07-20 | 2            |
| 2019-07-21 | 2            |
+------------+--------------+ 
Explanation: Note that we do not care about days with zero active users.
</pre>

```sql
SELECT activity_date AS day,
       COUNT(DISTINCT user_id) AS active_users
FROM Activity
WHERE activity_date BETWEEN  ('2019-07-27'- INTERVAL 29 DAY) AND '2019-07-27'
      AND session_id IS NOT NULL
GROUP BY activity_date


select activity_date as day, count(distinct(user_id)) 
as active_users from Activity 
where datediff('2019-07-27', activity_date )<30
and activity_date <= '2019-07-27'
group by activity_date 
having active_users >0 ;


-- The DATEADD() function adds a time/date interval to a date and then returns the date.
select activity_date as day, count(distinct user_id) as active_users from activity
where activity_date> dateadd(day, -30, '2019-07-27') and activity_date<= '2019-07-27'
group by activity_date
```









<br /> <br /> <br /> **[1693. Daily Leads and Partners](https://leetcode.com/problems/daily-leads-and-partners/)**<br />
Table: `DailySales`<br />
<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| date_id     | date    |
| make_name   | varchar |
| lead_id     | int     |
| partner_id  | int     |
+-------------+---------+
This table does not have a primary key.
This table contains the date and the name of the product sold and the IDs of the lead and partner it was sold to.
The name consists of only lowercase English letters.
</pre>
Write an SQL query that will, for each `date_id` and `make_name`, return the number of **distinct** `lead_id`'s and **distinct** `partner_id`'s.
Return the result table in **any order**.
The query result format is in the following example.

>Example 1:<br />
<pre>
Input: 
DailySales table:
+-----------+-----------+---------+------------+
| date_id   | make_name | lead_id | partner_id |
+-----------+-----------+---------+------------+
| 2020-12-8 | toyota    | 0       | 1          |
| 2020-12-8 | toyota    | 1       | 0          |
| 2020-12-8 | toyota    | 1       | 2          |
| 2020-12-7 | toyota    | 0       | 2          |
| 2020-12-7 | toyota    | 0       | 1          |
| 2020-12-8 | honda     | 1       | 2          |
| 2020-12-8 | honda     | 2       | 1          |
| 2020-12-7 | honda     | 0       | 1          |
| 2020-12-7 | honda     | 1       | 2          |
| 2020-12-7 | honda     | 2       | 1          |
+-----------+-----------+---------+------------+
Output: 
+-----------+-----------+--------------+-----------------+
| date_id   | make_name | unique_leads | unique_partners |
+-----------+-----------+--------------+-----------------+
| 2020-12-8 | toyota    | 2            | 3               |
| 2020-12-7 | toyota    | 1            | 2               |
| 2020-12-8 | honda     | 2            | 2               |
| 2020-12-7 | honda     | 3            | 2               |
+-----------+-----------+--------------+-----------------+
Explanation: 
For 2020-12-8, toyota gets leads = [0, 1] and partners = [0, 1, 2] while honda gets leads = [1, 2] and partners = [1, 2].
For 2020-12-7, toyota gets leads = [0] and partners = [1, 2] while honda gets leads = [0, 1, 2] and partners = [1, 2].
</pre>

```sql
SELECT date_id, make_name, COUNT(DISTINCT lead_id) AS unique_leads, COUNT(DISTINCT partner_id) AS unique_partners
FROM dailysales
GROUP BY date_id,make_name
ORDER BY date_id


SELECT 
    date_id,
    make_name,
    COUNT(DISTINCT(lead_id)) AS unique_leads,
    COUNT(DISTINCT(partner_id)) AS unique_partners 
FROM 
    DailySales
GROUP BY 1,2;
```









<br /> <br /> <br /> **[1729. Find Followers Count](https://leetcode.com/problems/find-followers-count/)**<br />
Table: `Followers`<br />
<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| user_id     | int  |
| follower_id | int  |
+-------------+------+
(user_id, follower_id) is the primary key for this table.
This table contains the IDs of a user and a follower in a social media app where the follower follows the user.
</pre>
Write an SQL query that will, for each user, return the number of followers.<br />
Return the result table ordered by `user_id`.<br />
The query result format is in the following example.<br />

>Example 1:<br />
<pre>
Input: 
Followers table:
+---------+-------------+
| user_id | follower_id |
+---------+-------------+
| 0       | 1           |
| 1       | 0           |
| 2       | 0           |
| 2       | 1           |
+---------+-------------+
Output: 
+---------+----------------+
| user_id | followers_count|
+---------+----------------+
| 0       | 1              |
| 1       | 1              |
| 2       | 2              |
+---------+----------------+
Explanation: 
The followers of 0 are {1}
The followers of 1 are {0}
The followers of 2 are {0,1}
</pre>

```sql
Select user_id, count(distinct follower_id) as followers_count
from Followers
group by user_id;
```












<br /> <br /> <br /> **[586. Customer Placing the Largest Number of Orders](https://leetcode.com/problems/customer-placing-the-largest-number-of-orders/)**<br />
Table: `Orders`<br />
<pre>
+-----------------+----------+
| Column Name     | Type     |
+-----------------+----------+
| order_number    | int      |
| customer_number | int      |
+-----------------+----------+
order_number is the primary key for this table.
This table contains information about the order ID and the customer ID.
</pre>
Write an SQL query to find the `customer_number` for the customer who has placed **the largest number of orders**.<br />
The test cases are generated so that **exactly one customer** will have placed more orders than any other customer.<br />
The query result format is in the following example.<br />

>Example 1:<br />
<pre>
Input: 
Orders table:
+--------------+-----------------+
| order_number | customer_number |
+--------------+-----------------+
| 1            | 1               |
| 2            | 2               |
| 3            | 3               |
| 4            | 3               |
+--------------+-----------------+
Output: 
+-----------------+
| customer_number |
+-----------------+
| 3               |
+-----------------+
Explanation: 
The customer with number 3 has two orders, which is greater than either customer 1 or 2 because each of them only has one order. 
So the result is customer_number 3.
</pre>
**Follow up:** What if more than one customer has the largest number of orders, can you find all the `customer_number` in this case?<br />

```sql
SELECT customer_number AS 'customer_number'
FROM Orders
GROUP BY customer_number
ORDER BY COUNT(*) DESC
LIMIT 1


SELECT customer_number AS 'customer_number'
FROM OrderS
GROUP BY customer_number 
HAVING COUNT(order_number) = (SELECT MAX(Max_Order)
FROM (
SELECT COUNT(*) AS 'Max_Order'
FROM Orders 
GROUP BY customer_number ) 
AS New_Table)


SELECT customer_number
FROM orders
GROUP BY customer_number
ORDER BY COUNT(order_number) DESC
LIMIT 1
```












<br /> <br /> <br /> **[511. Game Play Analysis I](https://leetcode.com/problems/game-play-analysis-i/)**<br />
Table: `Activity`<br />
<pre>
+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| player_id    | int     |
| device_id    | int     |
| event_date   | date    |
| games_played | int     |
+--------------+---------+
(player_id, event_date) is the primary key of this table.
This table shows the activity of players of some games.
Each row is a record of a player who logged in and played a number of games (possibly 0) before logging out on someday using some device.
</pre>
Write an SQL query to report the **first login date** for each player.<br />
Return the result table in **any order**.<br />
The query result format is in the following example.<br />

>Example 1:<br />
<pre>
Input: 
Activity table:
+-----------+-----------+------------+--------------+
| player_id | device_id | event_date | games_played |
+-----------+-----------+------------+--------------+
| 1         | 2         | 2016-03-01 | 5            |
| 1         | 2         | 2016-05-02 | 6            |
| 2         | 3         | 2017-06-25 | 1            |
| 3         | 1         | 2016-03-02 | 0            |
| 3         | 4         | 2018-07-03 | 5            |
+-----------+-----------+------------+--------------+
Output: 
+-----------+-------------+
| player_id | first_login |
+-----------+-------------+
| 1         | 2016-03-01  |
| 2         | 2017-06-25  |
| 3         | 2016-03-02  |
+-----------+-------------+
</pre>

```sql
-- Aggregation using MIN:
SELECT player_id, MIN(event_date) AS first_login
FROM Activity
GROUP BY player_id;


-- Using a window to get FIRST_VALUE:
SELECT DISTINCT player_id, 
       FIRST_VALUE(event_date) OVER(PARTITION BY player_id ORDER BY event_date) AS first_login
FROM Activity;


select player_id, 
min(event_date) as first_login 
from activity group by player_id ;
```













<br /> <br /> <br /> **[1890. The Latest Login in 2020](https://leetcode.com/problems/the-latest-login-in-2020/)**<br />
Table: `Logins`<br />
<pre>
+----------------+----------+
| Column Name    | Type     |
+----------------+----------+
| user_id        | int      |
| time_stamp     | datetime |
+----------------+----------+
(user_id, time_stamp) is the primary key for this table.
Each row contains information about the login time for the user with ID user_id.
</pre>
Write an SQL query to report the **latest** login for all users in the year `2020`. Do **not** include the users who did not login in `2020`.<br />
Return the result table **in any order**.<br />
The query result format is in the following example.<br />

>Example 1:<br />
<pre>
Input: 
Logins table:
+---------+---------------------+
| user_id | time_stamp          |
+---------+---------------------+
| 6       | 2020-06-30 15:06:07 |
| 6       | 2021-04-21 14:06:06 |
| 6       | 2019-03-07 00:18:15 |
| 8       | 2020-02-01 05:10:53 |
| 8       | 2020-12-30 00:46:50 |
| 2       | 2020-01-16 02:49:50 |
| 2       | 2019-08-25 07:59:08 |
| 14      | 2019-07-14 09:00:00 |
| 14      | 2021-01-06 11:59:59 |
+---------+---------------------+
Output: 
+---------+---------------------+
| user_id | last_stamp          |
+---------+---------------------+
| 6       | 2020-06-30 15:06:07 |
| 8       | 2020-12-30 00:46:50 |
| 2       | 2020-01-16 02:49:50 |
+---------+---------------------+
Explanation: 
User 6 logged into their account 3 times but only once in 2020, so we include this login in the result table.
User 8 logged into their account 2 times in 2020, once in February and once in December. We include only the latest one (December) in the result table.
User 2 logged into their account 2 times but only once in 2020, so we include this login in the result table.
User 14 did not login in 2020, so we do not include them in the result table.
</pre>

```sql
select user_id , max(time_stamp) as last_stamp from Logins 
where time_stamp like '2020%'group by user_id;


SELECT USER_ID,MAX(TIME_STAMP) AS LAST_STAMP
FROM LOGINS
WHERE YEAR(TIME_STAMP) >= '2020-01-01 00:00:00'
AND YEAR(TIME_STAMP) <= '2020-12-31 23:59:59'
GROUP BY USER_ID
ORDER BY USER_ID


SELECT user_id, max(time_stamp) last_stamp
FROM Logins
WHERE year(time_stamp) = 2020
GROUP BY user_id
```















<br /> <br /> <br /> **[1741. Find Total Time Spent by Each Employee](https://leetcode.com/problems/find-total-time-spent-by-each-employee/)**<br />
Table: `Employees`<br />
<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| emp_id      | int  |
| event_day   | date |
| in_time     | int  |
| out_time    | int  |
+-------------+------+
(emp_id, event_day, in_time) is the primary key of this table.
The table shows the employees' entries and exits in an office.
event_day is the day at which this event happened, in_time is the minute at which the employee entered the office, and out_time is the minute at which they left the office.
in_time and out_time are between 1 and 1440.
It is guaranteed that no two events on the same day intersect in time, and in_time < out_time.
</pre>
Write an SQL query to calculate the total time **in minutes** spent by each employee on each day at the office. Note that within one day, an employee can enter and leave more than once. The time spent in the office for a single entry is `out_time - in_time`.<br />
Return the result table in **any order**.<br />
The query result format is in the following example.<br />

>Example 1:<br />
<pre>
Input: 
Employees table:
+--------+------------+---------+----------+
| emp_id | event_day  | in_time | out_time |
+--------+------------+---------+----------+
| 1      | 2020-11-28 | 4       | 32       |
| 1      | 2020-11-28 | 55      | 200      |
| 1      | 2020-12-03 | 1       | 42       |
| 2      | 2020-11-28 | 3       | 33       |
| 2      | 2020-12-09 | 47      | 74       |
+--------+------------+---------+----------+
Output: 
+------------+--------+------------+
| day        | emp_id | total_time |
+------------+--------+------------+
| 2020-11-28 | 1      | 173        |
| 2020-11-28 | 2      | 30         |
| 2020-12-03 | 1      | 41         |
| 2020-12-09 | 2      | 27         |
+------------+--------+------------+
Explanation: 
Employee 1 has three events: two on day 2020-11-28 with a total of (32 - 4) + (200 - 55) = 173, and one on day 2020-12-03 with a total of (42 - 1) = 41.
Employee 2 has two events: one on day 2020-11-28 with a total of (33 - 3) = 30, and one on day 2020-12-09 with a total of (74 - 47) = 27.
</pre>

```sql
SELECT  event_day AS day,emp_id,SUM(out_time - in_time) AS total_time FROM EMPLOYEES GROUP BY event_day,emp_id;


SELECT 
TO_CHAR(event_day, 'YYYY-MM-DD') AS "day", 
emp_id, 
SUM(out_time) - SUM(in_time) AS "total_time" 
FROM employees 
GROUP BY event_day, emp_id 
ORDER BY "total_time" DESC;
```












<br /> <br /> <br /> **[1393. Capital Gain/Loss](https://leetcode.com/problems/capital-gainloss/)**<br />
Table: `Stocks`<br />
<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| stock_name    | varchar |
| operation     | enum    |
| operation_day | int     |
| price         | int     |
+---------------+---------+
(stock_name, operation_day) is the primary key for this table.
The operation column is an ENUM of type ('Sell', 'Buy')
Each row of this table indicates that the stock which has stock_name had an operation on the day operation_day with the price.
It is guaranteed that each 'Sell' operation for a stock has a corresponding 'Buy' operation in a previous day. It is also guaranteed that each 'Buy' operation for a stock has a corresponding 'Sell' operation in an upcoming day.
</pre>
Write an SQL query to report the **Capital gain/loss** for each stock.<br />
The **Capital gain/loss** of a stock is the total gain or loss after buying and selling the stock one or many times.<br />
Return the result table in **any order**.<br />
The query result format is in the following example.<br />

>Example 1:<br />
<pre>
Input: 
Stocks table:
+---------------+-----------+---------------+--------+
| stock_name    | operation | operation_day | price  |
+---------------+-----------+---------------+--------+
| Leetcode      | Buy       | 1             | 1000   |
| Corona Masks  | Buy       | 2             | 10     |
| Leetcode      | Sell      | 5             | 9000   |
| Handbags      | Buy       | 17            | 30000  |
| Corona Masks  | Sell      | 3             | 1010   |
| Corona Masks  | Buy       | 4             | 1000   |
| Corona Masks  | Sell      | 5             | 500    |
| Corona Masks  | Buy       | 6             | 1000   |
| Handbags      | Sell      | 29            | 7000   |
| Corona Masks  | Sell      | 10            | 10000  |
+---------------+-----------+---------------+--------+
Output: 
+---------------+-------------------+
| stock_name    | capital_gain_loss |
+---------------+-------------------+
| Corona Masks  | 9500              |
| Leetcode      | 8000              |
| Handbags      | -23000            |
+---------------+-------------------+
Explanation: 
Leetcode stock was bought at day 1 for 1000$ and was sold at day 5 for 9000$. Capital gain = 9000 - 1000 = 8000$.
Handbags stock was bought at day 17 for 30000$ and was sold at day 29 for 7000$. Capital loss = 7000 - 30000 = -23000$.
Corona Masks stock was bought at day 1 for 10$ and was sold at day 3 for 1010$. 
It was bought again at day 4 for 1000$ and was sold at day 5 for 500$. At last, it was bought at day 6 for 1000$ and was sold at day 10 for 10000$. 
Capital gain/loss is the sum of capital gains/losses for each ('Buy' --> 'Sell') operation = (1010 - 10) + (500 - 1000) + (10000 - 1000) 
											   = 1000 - 500 + 9000 = 9500$.
</pre>

```sql 
SELECT stock_name, SUM(IF(operation='Buy', -price, price)) AS capital_gain_loss
FROM Stocks
GROUP BY stock_name


SELECT stock_name,
SUM( CASE WHEN operation = 'Sell' THEN PRICE ELSE 0 END)-
SUM( CASE WHEN operation = 'Buy' THEN PRICE ELSE 0 END)
AS 'capital_gain_loss'
FROM STOCKS
GROUP BY STOCK_NAME


with 
buy as (
    select stock_name, sum(price) as buy_price
    from Stocks 
    where operation = 'Buy' 
    group by stock_name
),
sell as (
    select stock_name, sum(price) as sell_price
    from Stocks 
    where operation = 'Sell' 
    group by stock_name
)
select b.stock_name, (s.sell_price - b.buy_price) as capital_gain_loss
from buy b inner join sell s 
on b.stock_name = s.stock_name
```











<br /> <br /> <br /> **[1407. Top Travellers](https://leetcode.com/problems/top-travellers/)**<br />
Table: `Users`<br />
<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| name          | varchar |
+---------------+---------+
id is the primary key for this table.
name is the name of the user.
</pre>
Table: `Rides`<br />
<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| user_id       | int     |
| distance      | int     |
+---------------+---------+
id is the primary key for this table.
user_id is the id of the user who traveled the distance "distance".
</pre>
Write an SQL query to report the distance traveled by each user.<br />
Return the result table ordered by `travelled_distance` in **descending order**, if two or more users traveled the same distance, order them by their `name` in **ascending order**.<br />
The query result format is in the following example.<br />

>Example 1:<br />
<pre>
Input: 
Users table:
+------+-----------+
| id   | name      |
+------+-----------+
| 1    | Alice     |
| 2    | Bob       |
| 3    | Alex      |
| 4    | Donald    |
| 7    | Lee       |
| 13   | Jonathan  |
| 19   | Elvis     |
+------+-----------+
Rides table:
+------+----------+----------+
| id   | user_id  | distance |
+------+----------+----------+
| 1    | 1        | 120      |
| 2    | 2        | 317      |
| 3    | 3        | 222      |
| 4    | 7        | 100      |
| 5    | 13       | 312      |
| 6    | 19       | 50       |
| 7    | 7        | 120      |
| 8    | 19       | 400      |
| 9    | 7        | 230      |
+------+----------+----------+
Output: 
+----------+--------------------+
| name     | travelled_distance |
+----------+--------------------+
| Elvis    | 450                |
| Lee      | 450                |
| Bob      | 317                |
| Jonathan | 312                |
| Alex     | 222                |
| Alice    | 120                |
| Donald   | 0                  |
+----------+--------------------+
Explanation: 
Elvis and Lee traveled 450 miles, Elvis is the top traveler as his name is alphabetically smaller than Lee.
Bob, Jonathan, Alex, and Alice have only one ride and we just order them by the total distances of the ride.
Donald did not have any rides, the distance traveled by him is 0.
</pre>

```sql
SELECT U.NAME, 
(CASE
    WHEN U.ID IN (SELECT USER_ID FROM RIDES) THEN SUM(R.DISTANCE)
    ELSE 0
    END) AS TRAVELLED_DISTANCE
FROM USERS U LEFT JOIN RIDES R ON U.ID = R.USER_ID
GROUP BY U.ID,R.USER_ID
ORDER BY TRAVELLED_DISTANCE DESC, NAME
```













<br /> <br /> <br /> **[1158. Market Analysis I](https://leetcode.com/problems/market-analysis-i/)**<br />
Table: `Users`<br />
<pre>
+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| user_id        | int     |
| join_date      | date    |
| favorite_brand | varchar |
+----------------+---------+
user_id is the primary key of this table.
This table has the info of the users of an online shopping website where users can sell and buy items.
</pre>
Table: `Orders`<br />
<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| order_id      | int     |
| order_date    | date    |
| item_id       | int     |
| buyer_id      | int     |
| seller_id     | int     |
+---------------+---------+
order_id is the primary key of this table.
item_id is a foreign key to the Items table.
buyer_id and seller_id are foreign keys to the Users table.
</pre>
Table: `Items`<br />
<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| item_id       | int     |
| item_brand    | varchar |
+---------------+---------+
item_id is the primary key of this table.
</pre>
Write an SQL query to find for each user, the join date and the number of orders they made as a buyer in `2019`.<br />
Return the result table in **any order**.<br />
The query result format is in the following example.<br />

>Example 1:<br />
<pre>
Input: 
Users table:
+---------+------------+----------------+
| user_id | join_date  | favorite_brand |
+---------+------------+----------------+
| 1       | 2018-01-01 | Lenovo         |
| 2       | 2018-02-09 | Samsung        |
| 3       | 2018-01-19 | LG             |
| 4       | 2018-05-21 | HP             |
+---------+------------+----------------+
Orders table:
+----------+------------+---------+----------+-----------+
| order_id | order_date | item_id | buyer_id | seller_id |
+----------+------------+---------+----------+-----------+
| 1        | 2019-08-01 | 4       | 1        | 2         |
| 2        | 2018-08-02 | 2       | 1        | 3         |
| 3        | 2019-08-03 | 3       | 2        | 3         |
| 4        | 2018-08-04 | 1       | 4        | 2         |
| 5        | 2018-08-04 | 1       | 3        | 4         |
| 6        | 2019-08-05 | 2       | 2        | 4         |
+----------+------------+---------+----------+-----------+
Items table:
+---------+------------+
| item_id | item_brand |
+---------+------------+
| 1       | Samsung    |
| 2       | Lenovo     |
| 3       | LG         |
| 4       | HP         |
+---------+------------+
Output: 
+-----------+------------+----------------+
| buyer_id  | join_date  | orders_in_2019 |
+-----------+------------+----------------+
| 1         | 2018-01-01 | 1              |
| 2         | 2018-02-09 | 2              |
| 3         | 2018-01-19 | 0              |
| 4         | 2018-05-21 | 0              |
+-----------+------------+----------------+
</pre>

```sql
SELECT U.user_id AS buyer_id, U.join_date, COUNT(A.order_date) AS orders_in_2019
FROM Users U
LEFT JOIN 
(SELECT buyer_id,order_date
FROM Orders
WHERE YEAR(order_date) = 2019
 ) AS A
ON U.user_id = A.buyer_id
GROUP BY U.user_id


SELECT U.USER_ID AS buyer_id, U.JOIN_DATE AS join_date,
(
    CASE 
        WHEN U.USER_ID IN (SELECT BUYER_ID FROM ORDERS WHERE ORDER_DATE LIKE '2019%') THEN COUNT(O.ITEM_ID)
        ELSE 0
    END
) AS orders_in_2019
FROM USERS U LEFT JOIN ORDERS O ON U.USER_ID = O.BUYER_ID AND YEAR(O.order_date)='2019'
GROUP BY U.USER_ID
ORDER BY USER_ID


select Users.user_id as buyer_id , join_date ,
(case when A.num is NULL then 0 else A.num end) as orders_in_2019 
from Users Left join
(select buyer_id , count(*) as num 
from Orders 
where order_date like "2019-%" group by buyer_id) as A
on Users.user_id = A.buyer_id; 


select u.user_id as "buyer_id",
       to_char(u.join_date,'YYYY-MM-DD') as "join_date",
       coalesce(uo.total,0) as "orders_in_2019"
from Users u
left outer join (select o.buyer_id, count(o.buyer_id) as total
      from Orders o
      where to_char(o.order_date, 'YYYY') = '2019'
      group by o.buyer_id
     ) uo
on u.user_id = uo.buyer_id;
```















<br /> <br /> <br /> **[182. Duplicate Emails](https://leetcode.com/problems/duplicate-emails/)**<br />
Table: `Person`<br />
<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| email       | varchar |
+-------------+---------+
id is the primary key column for this table.
Each row of this table contains an email. The emails will not contain uppercase letters.
</pre>
Write an SQL query to report all the duplicate emails.<br />
Return the result table in **any order**.<br />
The query result format is in the following example.<br />

>Example 1:<br />
<pre>
Input: 
Person table:
+----+---------+
| id | email   |
+----+---------+
| 1  | a@b.com |
| 2  | c@d.com |
| 3  | a@b.com |
+----+---------+
Output: 
+---------+
| Email   |
+---------+
| a@b.com |
+---------+
Explanation: a@b.com is repeated two times.
</pre>

```sql
SELECT EMAIL FROM PERSON
GROUP BY EMAIL
HAVING COUNT(EMAIL) > 1


select DISTINCT p1.email from Person p1 ,Person p2 where p1.email=p2.email and p1.id != p2.id;


-- create a CTE that finds duplicate emails:
WITH CTE AS (
    SELECT
        email,
        ROW_NUMBER() OVER(PARTITION BY email ORDER BY email) AS row_num
    FROM Person
)


SELECT
    -- select distinct emails:
    DISTINCT email AS Email
-- from CTE:
FROM CTE
-- filter for rows greater than 1:
WHERE row_num > 1;
```











<br /> <br /> <br /> **[1050. Actors and Directors Who Cooperated At Least Three Times](https://leetcode.com/problems/actors-and-directors-who-cooperated-at-least-three-times/)**<br />
Table: `ActorDirector`<br />
<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| actor_id    | int     |
| director_id | int     |
| timestamp   | int     |
+-------------+---------+
timestamp is the primary key column for this table.
</pre>
Write a SQL query for a report that provides the pairs `(actor_id, director_id)` where the actor has cooperated with the director at least three times.<br />
Return the result table in **any order**.<br />
The query result format is in the following example.<br />

>Example 1:<br />
<pre>
Input: 
ActorDirector table:
+-------------+-------------+-------------+
| actor_id    | director_id | timestamp   |
+-------------+-------------+-------------+
| 1           | 1           | 0           |
| 1           | 1           | 1           |
| 1           | 1           | 2           |
| 1           | 2           | 3           |
| 1           | 2           | 4           |
| 2           | 1           | 5           |
| 2           | 1           | 6           |
+-------------+-------------+-------------+
Output: 
+-------------+-------------+
| actor_id    | director_id |
+-------------+-------------+
| 1           | 1           |
+-------------+-------------+
Explanation: The only pair is (1, 1) where they cooperated exactly 3 times.
</pre>

```sql
SELECT
    actor_id,
    director_id
FROM ActorDirector
GROUP BY actor_id, director_id
HAVING COUNT(timestamp) > 2


with cte as
(
select actor_id, director_id, count(timestamp) over (partition by actor_id,director_id) countn
    from actordirector
)
select distinct actor_id, director_id from cte where countn>=3;
```










<br /> <br /> <br /> **[1587. Bank Account Summary II](https://leetcode.com/problems/bank-account-summary-ii/)**<br />
Table: `Users`<br />
<pre>
+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| account      | int     |
| name         | varchar |
+--------------+---------+
account is the primary key for this table.
Each row of this table contains the account number of each user in the bank.
There will be no two users having the same name in the table.
</pre>
Table: `Transactions`<br />
<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| trans_id      | int     |
| account       | int     |
| amount        | int     |
| transacted_on | date    |
+---------------+---------+
trans_id is the primary key for this table.
Each row of this table contains all changes made to all accounts.
amount is positive if the user received money and negative if they transferred money.
All accounts start with a balance of 0.
</pre>
Write an SQL query to report the name and balance of users with a balance higher than `10000`. The balance of an account is equal to the sum of the amounts of all transactions involving that account.<br />
Return the result table in **any order**.<br />
The query result format is in the following example.<br />

>Example 1:<br />
<pre>
Input: 
Users table:
+------------+--------------+
| account    | name         |
+------------+--------------+
| 900001     | Alice        |
| 900002     | Bob          |
| 900003     | Charlie      |
+------------+--------------+
Transactions table:
+------------+------------+------------+---------------+
| trans_id   | account    | amount     | transacted_on |
+------------+------------+------------+---------------+
| 1          | 900001     | 7000       |  2020-08-01   |
| 2          | 900001     | 7000       |  2020-09-01   |
| 3          | 900001     | -3000      |  2020-09-02   |
| 4          | 900002     | 1000       |  2020-09-12   |
| 5          | 900003     | 6000       |  2020-08-07   |
| 6          | 900003     | 6000       |  2020-09-07   |
| 7          | 900003     | -4000      |  2020-09-11   |
+------------+------------+------------+---------------+
Output: 
+------------+------------+
| name       | balance    |
+------------+------------+
| Alice      | 11000      |
+------------+------------+
Explanation: 
Alice's balance is (7000 + 7000 - 3000) = 11000.
Bob's balance is 1000.
Charlie's balance is (6000 + 6000 - 4000) = 8000.
</pre>

```sql
SELECT a.name, SUM(b.amount) balance
FROM Users a
JOIN Transactions b
ON a.account = b.account
GROUP BY a.account
HAVING balance > 10000;


WITH cte 
AS (SELECT name, amount, u.account AS act 
	FROM Users u 
	JOIN Transactions t 
	ON u.account=t.account) 
SELECT name, SUM(amount) AS balance 
FROM cte 
GROUP BY act 
HAVING SUM(amount)>10000;


SELECT * FROM
(
    SELECT 
    u.name AS "NAME", 
    SUM(t.amount) AS "BALANCE" FROM users u
    NATURAL JOIN
    transactions t
    GROUP BY account, u.name
) WHERE balance > 10000;
```














<br /> <br /> <br /> **[1084. Sales Analysis III](https://leetcode.com/problems/sales-analysis-iii/)**<br />
Table: `Product`<br />
<pre>
+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| product_id   | int     |
| product_name | varchar |
| unit_price   | int     |
+--------------+---------+
product_id is the primary key of this table.
Each row of this table indicates the name and the price of each product.
</pre>
Table: `Sales`<br />
<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| seller_id   | int     |
| product_id  | int     |
| buyer_id    | int     |
| sale_date   | date    |
| quantity    | int     |
| price       | int     |
+-------------+---------+
This table has no primary key, it can have repeated rows.
product_id is a foreign key to the Product table.
Each row of this table contains some information about one sale.
</pre>
Write an SQL query that reports the **products** that were **only** sold in the first quarter of `2019`. That is, between `2019-01-01` and `2019-03-31` inclusive.
Return the result table in **any order**.
The query result format is in the following example.

>Example 1:<br />
<pre>
Input: 
Product table:
+------------+--------------+------------+
| product_id | product_name | unit_price |
+------------+--------------+------------+
| 1          | S8           | 1000       |
| 2          | G4           | 800        |
| 3          | iPhone       | 1400       |
+------------+--------------+------------+
Sales table:
+-----------+------------+----------+------------+----------+-------+
| seller_id | product_id | buyer_id | sale_date  | quantity | price |
+-----------+------------+----------+------------+----------+-------+
| 1         | 1          | 1        | 2019-01-21 | 2        | 2000  |
| 1         | 2          | 2        | 2019-02-17 | 1        | 800   |
| 2         | 2          | 3        | 2019-06-02 | 1        | 800   |
| 3         | 3          | 4        | 2019-05-13 | 2        | 2800  |
+-----------+------------+----------+------------+----------+-------+
Output: 
+-------------+--------------+
| product_id  | product_name |
+-------------+--------------+
| 1           | S8           |
+-------------+--------------+
Explanation: 
The product with id 1 was only sold in the spring of 2019.
The product with id 2 was sold in the spring of 2019 but was also sold after the spring of 2019.
The product with id 3 was sold after spring 2019.
We return only product 1 as it is the product that was only sold in the spring of 2019.
</pre>

```sql
select p.product_id, p.product_name
from Product p
inner join Sales s on p.product_id = s.product_id
group by s.product_id
having min(sale_date) >= '2019-01-01'
and max(sale_date) <= '2019-03-31';


select p.product_id, p.product_name
from Product p
left join Sales s
on p.product_id = s.product_id
group by p.product_id
having sum(s.sale_date between '2019-01-01' and '2019-03-31') = count(s.sale_date) 
```

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

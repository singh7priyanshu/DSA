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

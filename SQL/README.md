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

# Leetcode SQL
## SQL Exercise 1:
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
</pre><br />

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
</pre><br />

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
</pre><br />
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
</pre><br />
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
</pre><br />

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
</pre><br />
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
</pre><br />
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
</pre><br />

```sql
-- using left join 
SELECT name as Customers FROM Customers c 
        LEFT JOIN Orders o
            ON c.id = o.customerId
                WHERE o.customerId IS NULL;

-- using not in 
SELECT name as Customers FROM Customers WHERE id not in (SELECT customerId FROM Orders);
```

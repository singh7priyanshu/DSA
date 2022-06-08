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

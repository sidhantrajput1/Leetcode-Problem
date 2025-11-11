# Write your MySQL query statement below
SELECT (
    SELECT DISTINCT salary FROM Employee
    ORDER BY salary DESC
    lIMIT 1 OFFSET 1
) AS SecondHighestSalary;

-- DISTINCT means return only unique value 
-- ORDER BY salary DESC means sort the salary in descending form like 5, 4, 3, 2, 1
-- LIMIT 1 means return one first row of table 
-- OFFSET 1 means skip the first 1 row return the rest of row 
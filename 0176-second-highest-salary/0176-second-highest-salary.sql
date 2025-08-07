# Write your MySQL query statement below
SELECT (
    SELECT DISTINCT salary FROM Employee
    ORDER BY salary DESC
    lIMIT 1 OFFSET 1
) AS SecondHighestSalary;
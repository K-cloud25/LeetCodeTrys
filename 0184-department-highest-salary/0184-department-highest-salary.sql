select d.name as Department, e.name as Employee, e.salary as Salary
from (
    select *, rank() over (partition by departmentId order by salary desc) as rnk
    from Employee
    )e

join Department d
on departmentId = d.id
where e.rnk = 1
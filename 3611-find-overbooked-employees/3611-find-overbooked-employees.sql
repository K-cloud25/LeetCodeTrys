with week_filter as (
    select*, sum(duration_hours) as t
    from (
        select *, WEEKOFYEAR(meeting_date)as week_year,
        year(meeting_date) as Y
        from meetings 
    ) as sub
    group by employee_id, week_year, Y
    having sum(duration_hours) > 20
),

meeting_heavy_filter as 
(
    select employee_id, count(employee_id) as meeting_heavy_weeks
    from week_filter
    group by employee_id
    having count(employee_id) > 1
)

select a.employee_id, employee_name, department, meeting_heavy_weeks
from meeting_heavy_filter as a
join employees as b
    on a.employee_id = b.employee_id
order by meeting_heavy_weeks desc, employee_name asc

select ip, count(*) as invalid_count
from logs
where ip not regexp '^[0-9]+\.[0-9]+\.[0-9]+\.[0-9]+$' 
or ip REGEXP '(^|\\.)0[0-9]+' or 
ip NOT REGEXP '^(25[0-5]|2[0-4][0-9]|1?[0-9]{1,2})(\\.(25[0-5]|2[0-4][0-9]|1?[0-9]{1,2})){3}$'
group by ip
order by count(*) desc, ip desc

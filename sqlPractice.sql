--  https://discuss.codechef.com/external-redirect/?url=https://mindmajix.com/sql-interview-questions
-- https://discuss.codechef.com/external-redirect/?url=https://www.janbasktraining.com/blog/sql-interview-questions/
-- https://discuss.codechef.com/external-redirect/?url=https://www.geeksforgeeks.org/sql-interview-questions/
-- https://discuss.codechef.com/external-redirect/?url=https://www.softwaretestinghelp.com/50-popular-sql-interview-questions-for-testers/
-- https://discuss.codechef.com/external-redirect/?url=https://www.techbeamers.com/sql-query-questions-answers-for-practice/


select * from workerss where firstname = 'Vipul' or firstname = 'Satish'
select * from workerss where firstname in ('Vipul', 'Satish')

select * from workerss where firstname not in ('Vipul', 'Satish')

select * from workerss where dept like 'Admin'

select * from workerss where firstname like '%a%'

select * from workerss where firstname like 'a%'

select * from workerss where firstname like '%h' and length(firstname) = 6;
select * from workerss where firstname like '_____h';


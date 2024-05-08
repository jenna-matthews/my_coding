/*still needs work!!!*/
/*The objective with this query (probably needs to be combined with an application so that it can move through an array) 
is to take a table with suspected duplicate values like this example and return all the fields that differ between the duplicate records
(basically to save the time/trouble/etc of the analyst looking at each field for each duplication to see if there are differences)
*/

--given a database
use glynnsource2

--given a table 
declare @table varchar(50)
set @table = 'rms_citation'

--get the columns in the given table
select column_name from INFORMATION_SCHEMA.columns
	where table_name = @table
order by ORDINAL_POSITION

--given a column with suspected/confirmed duplicate values
declare @dupColumn varchar(50)
set @dupColumn = 'citation_id'
--also given a column as the pk for the table
declare @pkColumn varchar(50)
set @pkColumn = 'seqnum'

--get the pk values having duplication dupColumn values for comparison
select distinct(citation_id) 
from rms_citation 
group by citation_id having count(@pkcolumn) > 1


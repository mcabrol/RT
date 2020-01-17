#!/bin/sh

function moment()
{
	day=$(( (input_date-now)/86400 ))
	if [ $day -gt "30" ]
	then
		while [ $day -gt "30" ]
		do
			month=$(( month+=1 ))
			day=$(( day-30 ))
		done
		printf '🔥  %s in \033[31;1m%d\033[0m months and \033[31;1m%d\033[0m days\n' "$name" "$month" "$day"
	else
		printf '🔥  %s in \033[31;1m%d\033[0m days\n' "$name" "$day"
	fi
	}

	name=Blackhole
	input_date=$(date -j -f "%b %d %Y %H:%M:%S" "May 6 2020 22:19:00" +%s)
	now=$(date +%s)

	moment $name $now $input_date

	name=Rtv1
	input_date=$(date -j -f "%b %d %Y %H:%M:%S" "Feb 1 2020 00:00:00" +%s)
	now=$(date +%s)

	moment $name $now $input_date

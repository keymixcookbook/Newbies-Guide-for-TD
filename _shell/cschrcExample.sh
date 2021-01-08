# Example c shell script

setappgroup default

# SET ENV FOR THE CURRENT SHOW
setenv MYSHOW tag

# SET SHOTS FOR THE CURRENT SHOW

## Craw List of Shows
set show_shots = ( `ls /shots/$MYSHOW | xargs -n 1 | sed 's:/::g' | sort` )

## Set alias based on shot name
foreach show_shot( $show_shots )
	alias $show_shot "ss $MYSHOW/$show_shot; cd /shots/$MYSHOW/$show_shot"
	clear # Clear alias printing
end

# Change Prompt display
if ($?prompt) then
	if ($?SHOT) then
		set prompt = "%{\033[32m%} %B[%n@%m]%{\033[36m%} $SHOW/%SHOT %{\033[33m%}%/ > %{\033[0m%}b"
	else
		set prompt = "%{\033[32m%} %B[%n@%m]%{\033[33m%}%/ > %{\033[0m%}%b"
	endif
endif

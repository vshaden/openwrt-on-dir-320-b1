# Установка #

зайдите на роутер по ssh

затем `vi /usr/bin/balance`, нажмите i

вставьте код (в putty - ПКМ в окне редактора):
```
#!/bin/sh
# design by garynych 08.31.2012

n=2;    #set port
req=AA180C3602; #balance request
rm -f /tmp/balance
rm -f /tmp/bal
F=”/dev/ttyUSB$n”
echo -e “AT+CUSD=1,$req,15\r”>$F
sleep 2
cat $F  | grep “+CUSD:”  > /tmp/bal &
sleep 3; killall cat
while read line
do
line1=${line%\”*}
line2=${line1##*\”}
done < /tmp/bal

decode_ucs2() {
local text=”$1″

while [ -n "$text" ]; do
local code=”$((0x${text:0:4}))”

if [ $code -le 127 ]; then
echo -en \\x$(printf “%02x” $code)
elif [ $code -le 2047 ]; then
echo -en \\x$(printf “%02x” $(((($code >>  6) & 0x1F) | 0xC0)))
echo -en \\x$(printf “%02x” $(( ($code        & 0x3F) | 0×80)))
elif [ $code -le 65535 ]; then
echo -en \\x$(printf “%02x” $(((($code >> 12) & 0x0F) | 0xE0)))
echo -en \\x$(printf “%02x” $(((($code >>  6) & 0x3F) | 0×80)))
echo -en \\x$(printf “%02x” $((( $code        & 0x3F) | 0×80)))
elif [ $code -le 1114111 ]; then
echo -en \\x$(printf “%02x” $(((($code >> 18) & 0×07) | 0xF0)))
echo -en \\x$(printf “%02x” $(((($code >> 12) & 0x3F) | 0×80)))
echo -en \\x$(printf “%02x” $(((($code >>  6) & 0x3F) | 0×80)))
echo -en \\x$(printf “%02x” $((( $code        & 0x3F) | 0×80)))
else
echo -n “?”
fi

text=”${text:4}”
done

echo “”
}

decode_ucs2 “$line2″>/tmp/balance &
sleep 1
cat /tmp/balance

exit 0
```

значение переменной n - командный интерфейс модема (список всех интерфейсов `ls /dev/ttyUSB*`)

значение переменной request - ussd команда, кодированная в ucs2:
|`AA180C3602`|`*100#`||
|:-----------|:------|:|
|`A3180C3602`|`#100#`|возвращается текст на английском|
|`AA184C3602`|`*102#`||
|`A3184C3602`|`*102#`|возвращается текст на английском|

конвертер http://smstools3.kekekasvi.com/topic.php?id=288

сохраните, нажав ESC, затем :wq (поочередно)

дайте права на исполнение `chmod +x /usr/bin/balance`

в веб-интерфейсе system->custom commands->configure->add

в поле description - пишем, например, balance

в поле command - /usr/bin/balance

нажимаем save&apply

теперь скрипт доступен в system->custom commands->dashboard
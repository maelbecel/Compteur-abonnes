token="EAAtd62b7rOUBAKpR8c38vRZBUadhx7VvozHVfoSfdXSJdckZCJzLbo8hYWVslySzEaYphcTTyqyGsqOjIiUWd9H247sDSiebHCO4N9VLNwnZCvSTXZBFX2iLg6PN0EfCzeuokcHqRTpZARfPmrWsZAEQnHK9KgpURFZC7tr0NmV0pZCUlmR7pyZAvua1rbhuRTZAJ5wunZAMDZAcTggGQXmqlK5VTtQZAQ1J21ZCr7tzy4IKVvZAMItpaA4fWnU"
res=$(curl -s -i -X GET "https://graph.facebook.com/v12.0/me?fields=friends&access_token=$token")
echo $res | tr ":}" "\n\n" | grep -A 1 "total_count" | tail -n 1


#include "http_parser.h"
#include <stdio.h>
#include <string.h>

const char *http_parser_url_fields_name(unsigned int field)
{
	switch(field) {
		case UF_SCHEMA:
			return "UF_SCHEMA";
		case UF_HOST:
			return "UF_HOST";
		case UF_PORT:
			return "UF_PORT";
		case UF_PATH:
			return "UF_PATH";
		case UF_QUERY:
			return "UF_QUERY";
		case UF_FRAGMENT:
			return "UF_FRAGMENT";
		case UF_USERINFO:
			return "UF_USERINFO";
		case UF_MAX: 
			return "UF_MAX";
		default:
			return nullptr;
	}

	return nullptr;
}

void dump_url (const char *url, const struct http_parser_url *u)
{
	unsigned int i;

	printf("\tfield_set: 0x%x, port: %u\n", u->field_set, u->port);
	for (i = 0; i < UF_MAX; i++)
	{
		printf("url_field:%s\t", http_parser_url_fields_name(i));
		if ((u->field_set & (1 << i)) == 0)
		{
			printf("\tfield_data[%u]: unset\n", i);
			continue;

		}

		printf("\tfield_data[%u]: off: %u len: %u part: \"%.*s\n\"", 
				i,
				u->field_data[i].off,
				u->field_data[i].len,
				u->field_data[i].len,
				url + u->field_data[i].off);
	}

}

int main()
{
	char *url = (char *)"http://www.baidu.com:8000/users?username=zhangsan#bar";

	printf("url:[%s]\n", url);

	struct http_parser_url u;
	int err = http_parser_parse_url(url, strlen(url), 0, &u);
	if(err == 0)
	{
		printf("field_set=%d\n", u.field_set);
		printf("port=%d\n", u.port);
		dump_url(url, &u);
	}

	printf("%.*s\n", 3, url+2);
	printf("%.*s\n", 3, url);

	return 0;
}


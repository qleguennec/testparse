/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 15:37:29 by qle-guen          #+#    #+#             */
/*   Updated: 2016/10/21 03:03:46 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libparse/libparse.h"
#include <stdio.h>
#include <string.h>

#define TESTNAME	printf("test:\t%s\n", __FUNCTION__);

#define START 		TESTNAME \
	int test = 0; \
	int ok = 0;

#define END			TESTNAME \
	printf("ok\t%d/%d\n\n", ok, test);

#define TEST(c, t)	test++; printf("%s\t", __FUNCTION__); \
	if (c && ++ok) printf("ok\t'%s'\n", t); \
	else printf("nok\t'%s'\n", t);

void		test_query(t_parse *p)
{
#define QUERY(x) TEST(query(x, p), x);
	START;
	QUERY("oneof");
	QUERY("noneof");
	QUERY("space");
	QUERY("&");
	QUERY("space");
	QUERY("skipspaces");
	QUERY("&");
	QUERY("satisfy");
	END;
}

void		test_run_parser(t_parse *p)
{
#define RUN_PARSER(x) TEST(!strcmp(run_parser(x, "", p), "test"), x)
	START;
	RUN_PARSER("		     test");
	RUN_PARSER("     test");
	END;
}

int			main(void)
{
	t_parse	p;

	parse_init(&p);
	test_query(&p);
	test_run_parser(&p);
}

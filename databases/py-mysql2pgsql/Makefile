# $FreeBSD$

PORTNAME=	mysql2pgsql
PORTVERSION=	0.1.6
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	databases python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py-${PORTNAME}-${PORTVERSION}

MAINTAINER=	c.kworr@gmail.com
COMMENT=	Tool for migrating/converting from MySQL to PostgreSQL

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}MySQLdb>=1.2.3:${PORTSDIR}/databases/py-MySQLdb \
		${PYTHON_PKGNAMEPREFIX}psycopg2>=2.4.2:${PORTSDIR}/databases/py-psycopg2 \
		${PYTHON_PKGNAMEPREFIX}termcolor>=1.1.0:${PORTSDIR}/devel/py-termcolor \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.10.0:${PORTSDIR}/devel/py-yaml \
		${PYTHON_PKGNAMEPREFIX}pytz>0:${PORTSDIR}/devel/py-pytz

USES=		python:2
USE_PYTHON=	distutils autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	philipsoutham
GH_PROJECT=	py-${PORTNAME}

.include <bsd.port.mk>

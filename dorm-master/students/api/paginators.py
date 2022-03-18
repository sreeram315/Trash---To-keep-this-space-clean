import sys

from rest_framework.pagination import LimitOffsetPagination, PageNumberPagination


class StudentInfoLimitPagination(LimitOffsetPagination):
	default_limit = 3
	max_limit = sys.maxsize
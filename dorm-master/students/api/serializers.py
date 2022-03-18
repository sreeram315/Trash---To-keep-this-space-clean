from rest_framework.serializers import ModelSerializer, HyperlinkedIdentityField, SerializerMethodField

#
from students.models import StudentInfo

url_detail = HyperlinkedIdentityField(
	view_name = 'students-api-detail',
	lookup_field = 'slug'
		)


class StudentListSerializer(ModelSerializer):
	class Meta:
		model = StudentInfo
		fields = [
					'reg_no',
					'name',
					'cgpa',
					'section',
					'course'
		]


class StudentCreateSerializer(ModelSerializer):
	class Meta:
		model = StudentInfo
		fields = [
					'reg_no',
					'name',
					'cgpa',
					'section',
					'course'
		]


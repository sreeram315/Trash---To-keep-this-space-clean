from rest_framework.generics import ( ListAPIView, RetrieveAPIView, DestroyAPIView,
										 UpdateAPIView, CreateAPIView)
from rest_framework.permissions import ( AllowAny, IsAuthenticated, IsAdminUser, IsAuthenticatedOrReadOnly,
	)

from students.models import StudentInfo
# from .permissions import IsOwner
from .serializers import StudentListSerializer, StudentCreateSerializer
from .paginators import StudentInfoLimitPagination



class StudentListAPIView(ListAPIView):
	serializer_class = StudentListSerializer
	# permission_classes = [AllowAny]
	# pagination_class = StudentInfoLimitPagination


	def get_queryset(self):
		queryset = StudentInfo.objects.all()
		q  =  self.request.GET.get('q')
		if q:
			queryset = queryset.filter(name__icontains = q)
		return queryset

class StudentCreateAPIView(CreateAPIView):
	serializer_class = StudentCreateSerializer



# class StudentInfoCreateAPIView(CreateAPIView):
# 	queryset = StudentInfo.objects.all()
# 	serializer_class = StudentCreateSerializer

# 	def perform_create(self, serializer):
# 		serializer.save(owner = self.request.user)





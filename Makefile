LD = $(shell which g++)
CXX = $(shell which g++)
CXXFLAGS = -Wall
EXE = proj0
OBJS = driver.o Country.o Continent.o
DEPS = $(addprefix .,$(OBJS:.o=.d))

$(EXE): $(DEPS) $(OBJS)
	$(LD) $(LDFLAGS) $(LDLIBS) $(OBJS) -o $@

.%.d: %.cpp
	@$(RM) $@; \
	$(CXX) -MM -MF $@ -MT "$(<:.cpp=.o) $@" -c $(CPPFLAGS) $<

$(OBJS): %.o: %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

-include $(DEPS)

run: $(EXE)
	./$(EXE)

.PHONY: clean
clean:
	$(RM) $(OBJS) $(DEPS) $(EXE)
